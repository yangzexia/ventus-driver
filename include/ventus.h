/**
 * @file ventus.h
 * @brief this file defined some ventus driver API when running OpenCL program
 * @author yangzexia
 * @version 1.0
 * @date 2022-11-16
 * 
 * @copyright Tsinghua DSPLAB
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2022-11-16 <td>1.0     <td>yangzexia     <td>main程序和驱动之间的接口
 * <tr><td>2022-12-15 <td>1.1     <td>yangzexia     <td>增加了执行所有kernel并返回id的接口
 * </table>
 */
#ifndef __VT_DRIVER_H__
#define __VT_DRIVER_H__

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <queue>

#include "processor.h"
//#ifdef __cplusplus
//extern "C" {
//#endif

typedef void* vt_device_h; ///< 类型定义，指向vt_device类的指针

typedef void* vt_buffer_h; ///< 类型定义，指向vt_buffer类的指针


#define MAX_TIMEOUT               (60*60*1000)   // 1hr 


/// @brief 【已实现】打开并连接一个GPGPU设备
/// @param hdevice 指向设备的指针
/// @return 若无错误则返回0，否则返回-1
int vt_dev_open(vt_device_h* hdevice);

/// @brief 【已实现】当所有操作完成时，关闭设备
/// @param hdevice 指向设备的指针
/// @return 若无错误则返回0，否则返回-1
int vt_dev_close(vt_device_h hdevice);

/// return device configurations
// int vt_dev_caps(vt_device_h* hdevice, uint32_t caps_id, uint64_t *value);


/// @brief 【已实现】为设备分配buffer
/// @param hdevice 指向设备的指针
/// @param size buffer大小
/// @param hbuffer 指向vt_buffer的指针
/// @return 若无错误则返回0，否则返回-1
int vt_buf_alloc(vt_device_h hdevice, uint64_t size, vt_buffer_h* hbuffer);

/// @brief 【已实现】释放buffer
/// @param hbuffer 指向vt_buffer的指针
/// @return 若无错误则返回0，否则返回-1
int vt_buf_free(vt_buffer_h hbuffer);

/// @brief 【已实现】获取指向buffer的指针，用于host端访问buffer
/// @param hbuffer 指向类vt_buffer的指针
/// @return 若无错误则返回0，否则返回-1
void* vt_host_ptr(vt_buffer_h hbuffer);


//int vt_mem_alloc(vt_device_h hdevice, uint64_t size, uint64_t* dev_vaddr, int taskID);

/// @brief 【已实现】以任务为单位，在GPGPU设备上分配虚拟内存空间（创建根页表）
/// @param hdevice 指向设备的指针
/// @param taskID 任务ID，需要从0开始迭加分配
/// @return 若无错误则返回0，否则返回-1
int vt_mem_alloc(vt_device_h hdevice, int taskID);


/// @brief 【已实现】释放任务对应的虚拟内存空间和已分配的物理空间（删除根页表）
/// @param hdevice 指向设备的指针
/// @param taskID 任务ID
/// @return 若无错误则返回0，否则返回-1
int vt_mem_free(vt_device_h hdevice, int taskID);


/// @brief 【已实现】将数据从buffer复制到设备内存
/// @param hbuffer 指向类vt_buffer的指针
/// @param dev_vaddr 设备端保存数据的起始虚拟地址
/// @param size 数据大小
/// @param taskID 任务ID
/// @return 若无错误则返回0，否则返回-1
int vt_copy_to_dev(vt_buffer_h hbuffer, uint64_t dev_vaddr, uint64_t size, int taskID);


/// @brief 【已实现】将数据从设备内存复制到buffer
/// @param hbuffer 指向类vt_buffer的指针
/// @param dev_vaddr 设备端保存数据的起始虚拟地址
/// @param size 数据大小
/// @param taskID 任务ID
/// @return 若无错误则返回0，否则返回-1
int vt_copy_from_dev(vt_buffer_h hbuffer, uint64_t dev_vaddr, uint64_t size, int taskID);


/// @brief 【已实现】设备开始执行任务
/// @param hdevice 指向设备的指针
/// @param taskID 任务ID
/// @param num_blocks 该任务需要分配的block数量
/// @param input_port GPGPU硬件输入信号
/// @return 若无错误则返回0，否则返回-1
int vt_start(vt_device_h hdevice, int taskID, int num_blocks, ventus::host_port_t* input_port);

/// @brief 【已实现】等待设备执行完成
/// @param hdevice 指向设备的指针
/// @param timeout 等待时间，单位为毫秒
/// @return 若无错误则返回0，否则返回-1
int vt_ready_wait(vt_device_h hdevice, uint64_t timeout);

/// @brief 【已实现】执行所有的kernel，并返回kernel ID
/// @param hdevice 指向设备的指针
/// @param finished_list 指向已完成kernel的list
/// @return 若无错误则返回0，否则返回-1
int vt_finish_all_kernel(vt_device_h hdevice, std::queue<int> *finished_list);

////////////////////////////// UTILITY FUNCIONS ///////////////////////////////

/// @brief 【已实现】上传kernel文件的一部分到设备，由vt_upload_kernel_file调用
/// @param device 指向设备的指针
/// @param content 数据内容
/// @param size 数据大小
/// @param taskID 对应的任务ID
/// @return 若无错误则返回0，否则返回-1
int vt_upload_kernel_bytes(vt_device_h device, const void* content, uint64_t size, int taskID);


/// @brief 【已实现】上传kernel文件到设备
/// @param device 指向设备的指针
/// @param filename kernel文件的名称
/// @param taskID 对应的任务ID
/// @return 若无错误则返回0，否则返回-1
int vt_upload_kernel_file(vt_device_h device, const char* filename, int taskID);

/// dump performance counters

/// @brief 【未实现】性能计数
/// @param device 指向设备的指针
/// @param stream 
/// @return 
int vt_dump_perf(vt_device_h device, FILE* stream);


//#ifdef __cplusplus
//}
//#endif

#endif // __VT_DRIVER_H__
