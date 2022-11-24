/**
 * @file processor.cpp
 * @brief processor类的实现
 * 
 * 主要功能：关联ram，启动，复位，执行（tick），通过总线和dram交互(如果有)，
 * 
 * @author yangzexia (yang-zx17@qq.com)
 * @version 1.0
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022  yangzexia@THU-DSPLAB
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2022-11-16 <td>1.0     <td>yangzexia     <td>创建
 * </table>
 */

#include "processor.h"

#include <verilated.h>
#include <VVentus.h>

#include <mem.h>

#include <iostream>
#include <unordered_map>
#include <list>

using namespace ventus;



/**
 * @brief Processor中定义的嵌套类的实现
 * @todo 各函数的具体实现
 */
class Processor::Impl{
public:
    Impl() {
        device_ = new VVentus();
        ram_ = nullptr;

        this->reset();
    }
    ~Impl(){
        delete device_;

    }

    void attach_ram(RAM* ram) {
        ram_ = ram;
    }
     /**
      * @brief GPGPU启动任务，传入任务需配置的参数
      * 每个任务由多个block组成，driver按block发送配置信息，在接收到一个block的信息之后，
      * GPGPU即开始执行，执行完毕之后返回相应block的ID
      * @return int 
      */
    int run() {
        int exitcode = 0;

        this->reset();
        /// @todo GPGPU任务完成时返回的信号
        while(device_->busy()){
            this->tick();
            exitcode = -1;///< 发生异常返回值
        }

        this->wait(5);
        
        return exitcode;
    }
    /// @todo 打印ram访问请求的函数
    void cout_flush(){

    }
    /**
     * @brief   GPGPU启动前复位  
     * @return int 
     */
    void start(const host_port_t* input_sig) {
        int exitcode = 0;
        this->reset();
        ///配置寄存器的操作
        
    }

private:
    void reset(){
        device_->reset = 1;
        for(int i = 0; i < RESET_DELAY; i++){
            device_->clock = 0;
            device_->eval();
            device_->clock = 1;
            device_->eval();
        }
        device_->reset = 0;
        
        //this->cout_flush();
    }

    void tick(){
        device_->clock = 0;
        this->eval();

        device_->clock = 1;
        this->eval();

        /// @todo ram的tick实现
    }

    void eval(){
        device_->eval();
    }

    void wait(int cycle){
        for(int i = 0; i < cycle; i++){
            this->tick();
        }
    }

private:
    VVentus *device_; ///< GPGPU
    RAM* ram_; ///< GPGPU的ram

    typedef struct {

    } mem_port_t; ///< GPGPU和ram之间的接口信号
};


Processor::Processor()
    :impl_(new Impl())
{}

Processor::~Processor(){
    delete impl_;
}
void Processor::attach_ram(RAM* mem) {
    impl_->attach_ram(mem);
}

int Processor::run() {
    return impl_->run();
}
int Processor::start(const host_port_t* input_sig) {
    return impl_->start(input_sig);
}