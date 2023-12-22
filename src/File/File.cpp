#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "File.h"
using namespace std;

/**
 * @brief 用于最后写日志&stats命令 获取当前文件的工作时长
 *
 * @return 工作时间(min)
 */
int File::getWorkingTime(){
    return working_time;
}


/**
 * @brief 用于第一次load的时候对名字的初始化
 *
 *
 * @param a 要写入的文件名字
 */
void File::setFileName(string a){
    filename = a;
}


/**
 * @brief 获得文件名字,其实是文件路径
 *
 *
 * @return filename
 */
string File::getFileName(){
    return filename;
}


/**
 * @brief 设置文件开始写的时间
 */
void File::setStartTime(){
    // 获取当前时间点
    chrono::system_clock::time_point now = chrono::system_clock::now();
    
    // 转换为分钟数
    chrono::minutes current_minutes = chrono::duration_cast<chrono::minutes>(now.time_since_epoch());
    
    // 将分钟数赋给 start_time 变量
    start_time = current_minutes.count();
}
/**
 * @brief 当load另外一个文件的时候停止当前文件的计时 
 * 并且把本次的工作时间加到文件的working time 里
 */
void File::storeWorkingTime(){
    // 获取当前时间点
    chrono::system_clock::time_point now = chrono::system_clock::now();
    
    // 转换为分钟数
    chrono::minutes current_minutes = chrono::duration_cast<chrono::minutes>(now.time_since_epoch());
    
    // 将分钟数赋给 current 变量
    int current_time = current_minutes.count();
    int time_span = current_time - start_time;
    time_span = time_span==0?1:time_span;
    working_time += time_span;
}