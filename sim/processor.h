/**
 * @file processor.h
 * @brief GPGPU设备的声明
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
#include <cstdint>
#include <queue>
#include "vt_memory.h"

#define RUN_DELAY   100 ///< 如果运行新任务时所有block都忙，最长等待时间
#define INSTSIZE64
#ifdef INSTSIZE64
    typedef uint64_t inst_len;
#else
    typedef uint32_t inst_len;
#endif
#pragma once
namespace ventus {

typedef struct {
    inst_len host_req_wg_id;
    inst_len host_req_num_wf;
    inst_len host_req_wf_size;
    inst_len host_req_start_pc;
    inst_len host_req_vgpr_size_total;
    inst_len host_req_sgpr_size_total;
    inst_len host_req_lds_size_total;
    inst_len host_req_gds_size_total;
    inst_len host_req_vgpr_size_per_wf;
    inst_len host_req_sgpr_size_per_wf;
    inst_len host_req_gds_baseaddr;
    bool host_req_valid;
    // bool host_req_ready;
    bool host_rsp_ready;
} host_port_t;///< GPGPU和主机之间进行配置参数传递的接口

// class Memory;

class Processor{
public:
    Processor();
    ~Processor();

    void attach_ram(Memory* ram);
    int start(const host_port_t* input_sig );
    int run(host_port_t* input_sig);
    std::queue<int> wait(uint64_t cycle);
private:

    class Impl;
    Impl* impl_;
};
}