#include <iostream>
#include <fstream>
#include <string>
#include "WorkSpace.h"
using namespace std;
/**
 * @brief 用于初始化workspace_name,filename...
 */
WorkSpace::WorkSpace(string filepath): File(){
    //初始化filename
    setFileName(filepath);
    //初始化workspace_name
    size_t lastSlashPos = filepath.find_last_of('/');
    string workspace_name;

    if (lastSlashPos == std::string::npos) {
        // 如果没有路径分隔符，则直接使用整个字符串作为文件名
        workspace_name = filepath;
    } else {
        // 获取文件名（不包括路径）
        workspace_name = filepath.substr(lastSlashPos + 1);
    }

    // 去掉 ".md" 后缀
    size_t dotPos = workspace_name.find_last_of('.');
    if (dotPos != std::string::npos && workspace_name.substr(dotPos) == ".md") {
        workspace_name = workspace_name.substr(0, dotPos);
    }
    set_workspace_name(workspace_name);
}
/**
 * @brief 用于初始化workspace的文件内容以及后面的修改，一般使用currentFileContent作为参数
 */
void WorkSpace::setWorkingSpaceContent(vector<string> a){
    workspace_content = a;

}
/**
 * @brief 用于初始化workspace的名字，以便后续的list-workspace命令
 * workspace_name 一般是文件路径的简化
 */
void WorkSpace::set_workspace_name(string a){
    workspace_name = a;
}
/**
 * @brief 删除当前的workspace
 */
void WorkSpace::kill(){
    delete this;
}