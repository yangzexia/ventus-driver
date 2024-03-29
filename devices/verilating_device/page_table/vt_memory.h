#pragma once
#include "page.h"

class Memory{
public:
    // PhysicalMemory 提供用物理地址读写数据的方法 writeData() readData()
    PhysicalMemory *pmm;
    Memory(uint64_t max_range){
        pmm = new PhysicalMemory(max_range);
    }
    Memory(const Memory& m) {
        if(m.pmm != nullptr)
            pmm  = new PhysicalMemory(*(m.pmm));
        else
            pmm = nullptr;
    }

    ~Memory(){
        delete pmm;
    }
    // 为任务创建根页表
    uint64_t createRootPageTable(){
        uint64_t root = pmm->findUsable(SV39::PageSize);
        if(root != 0)
            pmm->insertBlock(Block(root, SV39::PageSize, true));
        return root;
    }
    // 申请物理地址, 根据虚拟地址创建/写入页表项
    uint64_t allocateMemory(uint64_t root, uint64_t v_addr, uint64_t length){
        length = (length + SV39::PageSize - 1) / SV39::PageSize * SV39::PageSize;
        uint64_t p_addr = pmm->findUsable(length);
        if(p_addr == 0ull)
            return 0ull;
        if(pmm->insertBlock(Block(p_addr, length, true))) {
            return 0ull;
        }
        uint64_t pt_idx[3] = {~0ull, ~0ull, ~0ull};// rootpt, pt1, pt2
        for(uint64_t iter = 0ull; iter < length; iter += SV39::PageSize){
            if(SV39::VAextract((v_addr + iter), 0) != pt_idx[0]){ //may need a new entry in rootPT
                pt_idx[0] = SV39::VAextract((v_addr + iter), 0); // refresh pt_idx[0]
                if( (pmm->readWord<uint64_t>(root + pt_idx[0]*sizeof(uint64_t)) & SV39::V) == 0ull ){ // entry not exist in rootPT
                    auto pt1_addr = pmm->findUsable(SV39::PageSize);
                    if(!pt1_addr){
                        return 0;
                    }
                    pmm->insertBlock(Block(pt1_addr, SV39::PageSize, true)); // create and insert a PT1
                    uint64_t rootpt_entry = SV39::SetPTE(pt1_addr, SV39::V);
                    pmm->writeWord<uint64_t>(root + pt_idx[0]*sizeof(uint64_t), rootpt_entry);  // set rootPT entry
                }
            }
            uint64_t pt1_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(root + pt_idx[0]*sizeof(uint64_t)));

            if(SV39::VAextract(v_addr + iter, 1) != pt_idx[1]){ // may need a new entry in PT1
                pt_idx[1] = SV39::VAextract((v_addr + iter), 1); // refresh pt_idx[1]
                if( (pmm->readWord<uint64_t>(pt1_addr + pt_idx[1]*sizeof(uint64_t)) & SV39::V) == 0ull ){ // entry not exist in PT1
                    auto pt2_addr = pmm->findUsable(SV39::PageSize);
                    if(!pt2_addr){
                        return 0;
                    }
                    pmm->insertBlock(Block(pt2_addr, SV39::PageSize, true)); // create and insert a PT2
                    uint64_t pt1_entry = SV39::SetPTE(pt2_addr, SV39::V);
                    pmm->writeWord<uint64_t>(pt1_addr + pt_idx[1]*sizeof(uint64_t), pt1_entry);  // set PT1 entry
                }
            }
            uint64_t pt2_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt1_addr + pt_idx[1]*sizeof(uint64_t)));

            if(SV39::VAextract(v_addr + iter, 2) != pt_idx[2]){ // may need a new entry in PT2
                pt_idx[2] = SV39::VAextract((v_addr + iter), 2); // refresh pt_idx[2]
                if( (pmm->readWord<uint64_t>(pt2_addr + pt_idx[2]*sizeof(uint64_t)) & SV39::V) == 0ull ){ // entry not exist in PT2
                    uint64_t pt2_entry = SV39::SetPTE(p_addr + iter, SV39::R|SV39::W|SV39::X|SV39::V);
                    pmm->writeWord<uint64_t>(pt2_addr + pt_idx[2]*sizeof(uint64_t), pt2_entry);
                }
            }
        }
        return p_addr;
    }
    // 虚实地址转换
    uint64_t addrConvert(uint64_t root, uint64_t v_addr){
        auto pt1_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(root + SV39::VAextract(v_addr, 0)*sizeof(uint64_t)));
        if(!pt1_addr) return 0ull;
        auto pt2_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt1_addr + SV39::VAextract(v_addr, 1)*sizeof(uint64_t)));
        if(!pt2_addr) return 0ull;
        auto p_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt2_addr + SV39::VAextract(v_addr, 2)*sizeof(uint64_t)));
        if(!p_addr) return 0ull;
        return p_addr | (v_addr & 0xfffull);
    }
    // 用虚拟地址读数据
    int readDataVirtual(uint64_t root, uint64_t v_addr, uint64_t size, void *out){
        uint64_t vpn = 0ull; uint64_t len = 0ull;
        uint64_t p_addr = addrConvert(root, v_addr);
        for(uint64_t it = 0ull; it < size; it++){
            if(vpn != ((v_addr + it) & 0x0000007ffffff000ull)){
                if(len){
                    pmm->readData(p_addr, len, (uint8_t *)out + it - len);
                    p_addr = addrConvert(root, v_addr + it);
                }
                len = 0ull;
                vpn = (v_addr + it) & 0x0000007ffffff000ull;
            }
            if(!p_addr) return -1;
            len++;
        }
        pmm->readData(p_addr, len, (uint8_t *)out + size - len);
        return 0;
    }
    // 用物理地址读数据
    int readDataPhysical(uint64_t p_addr, uint64_t length, void *data){
        pmm->readData(p_addr, length, data);
        return 0;
    }
    template<class T> T readWordPhysical(uint64_t p_addr){
        return pmm->readWord<T>(p_addr);
    }
    template<class T> int readWordsPhysical(uint64_t p_addr, uint64_t num, T *data, const void *mask = nullptr){
        pmm->readWords<T>(p_addr, num, data, mask);
        return 0;
    }

    // 用虚拟地址写数据
    int writeDataVirtual(uint64_t root, uint64_t v_addr, uint64_t size, const void *in){
        uint64_t vpn = 0ull; uint64_t len = 0ull;
        uint64_t p_addr = addrConvert(root, v_addr);
        for(uint64_t it = 0ull; it < size; it++){
            if(vpn != ((v_addr + it) & 0x0000007ffffff000ull)){
                if(len){
                    pmm->writeData(p_addr, len, (uint8_t *)in + it - len);
                    p_addr = addrConvert(root, v_addr + it);
                }
                len = 0ull;
                vpn = (v_addr + it) & 0x0000007ffffff000ull;
            }
            if(!p_addr) return -1;
            len++;
        }
        pmm->writeData(p_addr, len, (uint8_t *)in + size - len);
        return 0;
    }

    // 用物理地址写数据
    int writeDataPhysical(uint64_t p_addr, uint64_t length, const void *data){
        return pmm->writeData(p_addr, length, data);
    }
    template<class T> int writeWordPhysical(uint64_t p_addr, const T in){
        return pmm->writeWord<T>(p_addr, in);
    }
    template<class T> int writeWordsPhysical(uint64_t p_addr, uint64_t num, const T *in, const void *mask = nullptr){
        return pmm->writeWords<T>(p_addr, num, in, mask);
    }

    // 释放物理内存, 改写页表项
    uint64_t releaseMemory(uint64_t root, uint64_t v_addr){
        uint64_t length = 0;
        uint64_t p_addr = addrConvert(root, v_addr);
        for(auto & block : *pmm->blocks){
            if(block == p_addr){
                length = block.size;
                break;
            }
            if(block > p_addr) return -1;
        }
        if(length == 0) return -1;
        pmm->removeBlock(p_addr);

        uint64_t pt_idx[3] = { ~0ull, ~0ull, ~0ull };
        for(uint64_t iter = 0ull; iter < length; iter += SV39::PageSize){
            auto pt1_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(root + SV39::VAextract(v_addr, 0)*sizeof(uint64_t)));
            auto pt2_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt1_addr + SV39::VAextract(v_addr, 1)*sizeof(uint64_t)));
            pt_idx[2] = SV39::VAextract(v_addr + iter, 2);
            pmm->writeWord<uint64_t>(pt2_addr + pt_idx[2]*sizeof(uint64_t), 0ull);
        }
        return 0;
    }
    // 清理无用页表
    uint64_t cleanPageTable(uint64_t root){
        for(uint64_t it0 = 0; it0 < SV39::PageSize; it0 += sizeof(uint64_t)){
            if((pmm->readWord<uint64_t>(root + it0) & SV39::V) == 0ull)
                continue;
            bool pt1_empty = true;
            auto pt1_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(root + it0));
            for(uint64_t it1 = 0; it1 < SV39::PageSize; it1 += sizeof(uint64_t)){
                if((pmm->readWord<uint64_t>(pt1_addr + it1) & SV39::V) == 0ull)
                    continue;
                bool pt2_empty = true;
                auto pt2_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt1_addr + it1));
                for(uint64_t it2 = 0; it2 < SV39::PageSize; it2 += sizeof(uint64_t)){
                    if((pmm->readWord<uint64_t>(pt2_addr + it2) & SV39::V) == 0ull)
                        continue;
                    else{
                        pt2_empty = false;
                        break;
                    }
                }
                if(pt2_empty){
                    pmm->removeBlock(pt2_addr); // delete pt2
                    pmm->writeWord<uint64_t>(pt1_addr + it1, 0ull); // clear entry in pt1
                    continue;
                }
                else{
                    pt1_empty = false;
                }
            }
            if(pt1_empty){
                pmm->removeBlock(pt1_addr); // delete pt1
                pmm->writeWord<uint64_t>(root + it0, 0ull); // clear entry in rootpt
            }
        }
        return 0;
    }
    // 清理整个任务
    uint64_t cleanTask(uint64_t root){
        for(uint64_t it0 = 0; it0 < SV39::PageSize; it0 += sizeof(uint64_t)){
            if((pmm->readWord<uint64_t>(root + it0) & SV39::V) == 0ull)
                continue;
            auto pt1_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(root + it0));
            for(uint64_t it1 = 0; it1 < SV39::PageSize; it1 += sizeof(uint64_t)){
                if((pmm->readWord<uint64_t>(pt1_addr + it1) & SV39::V) == 0ull)
                    continue;
                auto pt2_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt1_addr + it1));
                for(uint64_t it2 = 0; it2 < SV39::PageSize; it2 += sizeof(uint64_t)){
                    if((pmm->readWord<uint64_t>(pt2_addr + it2) & SV39::V) == 0ull)
                        continue;
                    else{
                        auto p_addr = SV39::PTE2PA(pmm->readWord<uint64_t>(pt2_addr + it2));
                        pmm->removeBlock(p_addr);
                    }
                }
                pmm->removeBlock(pt2_addr); // delete pt2
            }
            pmm->removeBlock(pt1_addr); // delete pt1
        }
        pmm->removeBlock(root);
        return 0ull;
    }
};
