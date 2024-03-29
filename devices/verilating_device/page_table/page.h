#include <cstdint>
#include <cstdlib>
#include <list>
#include <cstdio>
#include <iostream>
#include "SV39.h"

class Pages{
public:
    //const static uint64_t PageSize = 4096;
    uint8_t *data = nullptr;
    Pages(uint64_t size){
        //uint64_t page_num = (size + PageSize - 1) / PageSize;
        data = new uint8_t[size]();
    }
    ~Pages(){
        if(data != nullptr)
            delete []data;
    }
};

class Block{
public:
    Pages* pages;
    uint64_t addr;
    uint64_t size;

    Block(uint64_t addr, uint64_t size, bool create_pages = true):
    addr(addr), size(size){
        if(create_pages) {
            uint64_t num = (size + SV39::PageSize - 1) / SV39::PageSize;
            pages = new Pages(num * SV39::PageSize);
        }
        else
            pages = nullptr;
    }
    
    Block(const Block &blk):
    addr(blk.addr), size(blk.size), pages(nullptr){
        printf("Copy Cosntructor\n");
        if(blk.pages != nullptr){
			uint64_t num = (size + SV39::PageSize - 1) / SV39::PageSize;
			pages = new Pages(num * SV39::PageSize);
            for(uint64_t i = 0; i < num * SV39::PageSize; i++){
                pages->data[i] = blk.pages->data[i];
            }
        }
        else
            pages = nullptr;
    }

    Block(Block &&blk):
    addr(blk.addr), size(blk.size), pages(blk.pages){
        //printf("Move Constructor\n");
        blk.pages = nullptr;
    }

    ~Block(){
        if(pages != nullptr)
            delete pages;
    }

    bool operator<(const Block &another){
        return this->end() <= another.addr;
    }
    bool operator>(const Block &another){
        return this->addr >= another.end();
    }
    bool operator<(const uint64_t &pos){
        uint64_t end = this->addr + this->size;
        return end <= pos;
    }
    bool operator>(const uint64_t &pos){
        return this->addr > pos;
    }
    bool operator==(const uint64_t &pos){
        return this->addr <= pos && (this->addr + this->size) > pos;
    }
	Block& operator=(Block&& blk) noexcept {
		if (this != &blk) {
			addr = blk.addr;
			size = blk.size;
			pages = blk.pages;
			blk.pages = nullptr;
		}
		return *this;
	}

    uint64_t end() const{
        return addr + size;
    }

    int write(uint64_t base, uint64_t length, const void *data){ // 0 <= base < size
        if(base + length > size){
            printf("Input 0x%016lx + 0x%016lx is too long for block @0x%016lx\n", base, length, addr);
            return -1;
        }
        uint8_t *in = (uint8_t *)data;
        for(uint64_t i = 0ull; i < length && base + i < size; i++){
            pages->data[base + i] = in[i];
        }
        return 0;
    }
    int read(uint64_t base, uint64_t length, void *data){
        if(base + length > size){
            printf("Input 0x%016lx + 0x%016lx is too long for block @0x%016lx\n", base, length, addr);
            return -1;
        }
        uint8_t *out = (uint8_t *)data;
        for(uint64_t i = 0ull; i < length && base + i < size; i++){
            out[i] = pages->data[base + i];
        }
        return 0;
    }
};

class PhysicalMemory{
public:
    uint64_t max_range;
    std::list<Block>* blocks;
    std::list<Block>::iterator current_block;

    PhysicalMemory(uint64_t range){
        range = (range <= SV39::MaxPhyRange) ? range : SV39::MaxPhyRange;
        max_range = (range + SV39::PageSize - 1) / SV39::PageSize * SV39::PageSize;
        //max_addr = max_range - 1ull;
        blocks = new std::list<Block>;
        blocks->push_back(Block(0, 0x20000000, false));// 链表头，0-4K 默认不可用，范围可修改
        current_block = blocks->begin();
        blocks->push_back(Block(max_range, SV39::PageSize * 1, false)); // 链表尾，max_range是最大可用地址+1 （4K对齐）
    }
    PhysicalMemory(const PhysicalMemory& p) {
        if(p.blocks != nullptr) {
            this->blocks = new std::list<Block>;
            for(auto it : *p.blocks) {
                blocks->push_back(it);
            }
            max_range = p.max_range;
            current_block = this->blocks->begin();
        }
        else
            this->blocks = nullptr;
    }

    ~PhysicalMemory(){
        delete blocks;
    }

    //return 0: success, -1: fail
    int insertBlock(Block &&blk){
        if(*current_block > blk){
            while(current_block != blocks->begin()){
                current_block--;
                if(*current_block < blk){
                    blocks->emplace(std::next(current_block), std::move(blk));
                    return 0;
                }
            }
        }
        else if(*current_block < blk){
            while(current_block != blocks->end()){
                current_block++;
                if(*current_block > blk){
                    blocks->emplace(current_block, std::move(blk));
                    return 0;
                }
            }
        }
        else{
            printf("Block address conflict: 0x%016lx\n", blk.addr);
            return -1;
        }
        printf("Insert failed by unknown reason\n");
        return -1;
    }
    int removeBlock(uint64_t addr){
        for(auto iter = blocks->begin(); iter != blocks->end(); iter++){
            if(iter->addr <= addr && iter->addr + iter->size > addr){
                blocks->erase(iter);
                return 0;
            }
            if(iter->addr > addr)
                return -1;
        }
        //printf("Block address not exist: 0x%016lx\n", addr);
        return -1;
    }

    int writeData(uint64_t addr, uint64_t length, const void *data){
        for(auto &iter: *blocks){
            if(addr >= iter.addr &&
               addr + length <= iter.addr + iter.size){ // valid address
                if(iter.pages== nullptr){
                    printf("No pages in this block: 0x%016lx\n", addr);
                    return -1;
                }
                iter.write(addr - iter.addr, length, data);
                return 0;
            }
        }
        printf("Invalid address or too long data length: 0x%016lx\n", addr);
        return -1;
    }

    template<class T> int writeWord(uint64_t addr, const T in){
        T dat = in;
        return writeData(addr, sizeof(T), &dat);
    }
    template<class T> int writeWords(uint64_t addr, uint64_t num, const T* in, const void *mask = nullptr){
        if(mask == nullptr){
            writeData(addr, num*sizeof(T), in);
        }
        else{
            for(uint64_t i = 0; i < num; i++){
                uint8_t maskbit = (((uint8_t *)mask)[i/8] >> (i%8)) & '\x01';
                if(maskbit == '\x01'){
                    writeWord<T>(addr + i * sizeof(T), in[i]);
                }
            }
        }
        return 0;
    }

    int readData(uint64_t addr, uint64_t length, void *data){
        for(auto &iter: *blocks){
            if(addr >= iter.addr &&
               addr + length <= iter.addr + iter.size){
                if(iter.pages== nullptr){
                    printf("No pages in this block: 0x%016lx\n", addr);
                    return -1;
                }
				//如果要读取的地址和block的基地址不同，则对齐
                iter.read(addr - iter.addr, length, data);
                return 0;
            }
        }
        printf("Invalid address or too long data length: 0x%016lx\n", addr);
        return -1;
    }

    template<class T> T readWord(uint64_t addr){
        T out;
        int flag = readData(addr, sizeof(T), &out);
        if(!flag)
            return out;
        else
            return 0;
    }

    template<class T> int readWords(uint64_t addr, uint64_t num, T *data, const void *mask = nullptr){
        readData(addr, num * sizeof(T), data);
		//根据mask将对应的数据置零
        if(mask != nullptr){
            for(uint64_t i = 0; i < num; i++){
                uint8_t maskbit = (((uint8_t *)mask)[i/8] >> (i%8)) & '\x01';
                if(maskbit == '\x00'){
                    data[i] = 0;
                }
            }
        }
        return 0;
    }
// 这里可能有bug, 明天来看看
    uint64_t findUsable(uint64_t size){
        // not support megapage / gigapage yet
        size = (size + SV39::PageSize - 1) / SV39::PageSize * SV39::PageSize;
        uint64_t usable = 0ull;
        for(auto iter = blocks->begin(); std::next(iter) != blocks->end(); iter++){
            usable = usable <= iter->end() ? iter->end() : usable;
            if(*std::next(iter) > usable + size - 1){ // find ?
                if(usable + size <= max_range){ // find !
                    return usable;
                }else{
                    break; // fail
                }
            }
        }
        return 0ull;
    }
};