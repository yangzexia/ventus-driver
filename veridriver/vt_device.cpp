#include "vt_device.h"
#include <stdlib.h>
#include "vt_utils.h"
#include "MemConfig.h"



int vt_device::alloc_local_mem(inst_len size, inst_len *dev_addr, int taskID){
    if(size <= 0 || dev_addr == nullptr || taskID > roots.size()) 
        return -1;
    if(roots.size() == taskID) {
        uint64_t rootPage = ram_.createRootPageTable();
        roots.push_back(rootPage);
    }
    // 为device申请物理空间
    return ram_.allocateMemory(roots[taskID], *dev_addr, size) == 0 ? 0 : -1;

}

int vt_device::free_local_mem(int taskID){ 
    if(taskID >= roots.size() || roots[taskID] == 0)
        return -1;
    ram_.cleanTask(roots[taskID]);
    roots[taskID] = 0;
    return 0;
}

int vt_device::upload(int taskID, inst_len dest_addr, uint64_t size, void *data){
    if(taskID >= roots.size()|| roots[taskID] == 0)
        return -1;
    ram_.writeDataVirtual(roots[taskID], dest_addr+RODATA_BASE, size, data);

}

int vt_device::download(int taskID, uint64_t dest_data_addr, void *src_addr, uint64_t size){
    if(taskID >= roots.size()|| roots[taskID] == 0)
        return -1;    
    ram_.readDataVirtual(roots[taskID], dest_data_addr+GLOBALMEM_BASE, size, src_addr);
}
/**
 * @brief   发送任务，每个任务由多个block组成，每次调用run发送一个任务
 * 传入到硬件的wg_id由processor.run()决定，函数执行完成后会返回实际的wg_id,
 * 任务队列的数据结构为一个元素为unordered_map的list，list的每个元素代表一个任务，
 * 每次发送一个任务会在list中增加一个元素
 * unordered_map的每个key代表block ID，value表示该block是否执行完成。
 * @param input_sig 输入到GPGPU的信号，与硬件接口对应
 * @param num_block 这个任务由多少个块组成
 * @return int 0
 */
int vt_device::start(int num_block){
    // host_port_t* input_per_block;
    // *input_per_block = *input_sig;
    task_by_block_l.push_back(unordered_map<int, bool>());
    for(int i = 0; i < num_block; i++) {
        if(last_task_.valid()){
            task_by_block_l.back().emplace(last_task_.get(), 0);
        }
        last_task_ = std::async (std::launch::async, [&]() -> int {
            processor_.run(input_sig);
        });
    }
    return 0;
}
/**
 * @brief 等待一定时间，
 * @param  time              
 * @return int 
 */
int vt_device::wait(uint64_t time){
    // 如果所有已经启动的run()任务都完成
    if(!last_task_.valid());
    else {
        // 如果没有则等待到所有run()都完成
        uint64_t timeout = time / 1000;
        std::chrono::seconds wait_time(1);
        for(;;){
            auto status = last_task_.wait_for(wait_time);
            if (status == std::future_status::ready || timeout-- == 0)
                break;
        }
    }
    std::queue<int> finished_block = processor_.wait(time);
    // 根据GPGPU返回的block完成情况更新任务队列，将已完成的block ID与保存的list中的block ID比较
    while(!finished_block.empty()) {
        for(auto it=task_by_block_l.begin();it != task_by_block_l.end(); it++) {
                if(it->find(finished_block.front()) != it->end()) {
                    (*it)[finished_block.front()] = true;
                    finished_block.pop();
                }
            finished_block.pop();
            // 如果一个任务的所有block都完成，则将该任务pop掉，
                bool task_all_block_finished = true;
                for(auto& it_map : *it) {
                    if(it_map.second == false) {
                        task_all_block_finished = false;
                        break;
                    }
                }
                if(task_all_block_finished == true) {
                    it = task_by_block_l.erase(it);
                }
        }
    }
    return 0;
}

//Implementation of class vt_buffer
void* vt_buffer::data() const{
    return data_;
}
uint64_t vt_buffer::size() const{
    return size_;
}
vt_device* vt_buffer::device() const{
    return device_;
}
