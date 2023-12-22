#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include "WorkSpace.h"
#include "constants.h"
#include <filesystem>
#include "tool/tool.h"
namespace fs = std::filesystem;
extern string currentFileName;
extern vector<WorkSpace*> workspaces;
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
/**
 * @brief 得到存储的WorkspaceContent
 */
vector<string> WorkSpace::getWorkspaceContent(){
    return workspace_content;
}

/**
 * @brief 保存工作区的时候，生成不同的txt的名字
 */
string  SessionMemento::generateFileName() {
        ostringstream oss;
        oss << MementoPath<<"/workspace_" << workspaceCounter << ".txt";
        return oss.str();
}

/**
 * @brief 保存工作区到MementoPath下
 */
void SessionMemento::storeWorkspace(vector<WorkSpace*> workspaces){
     for (auto workspacePtr: workspaces) {
            //自动生成txt的名字
            string fileName = generateFileName();
            ofstream file(fileName);
            if (file.is_open()) {
                
                if(workspacePtr->getFileName().find(currentFileName)==workspacePtr->getFileName().size()-currentFileName.size()){
                    //如果这个是正在被打开的workspace
                    file << "*filename: " <<endl;
                    file << workspacePtr->getFileName()<< endl;
                }
                else{
                    file << "filename: " <<endl;
                    file << workspacePtr->getFileName()<< endl;
                }
                file<<"content:"<<endl;
                for (const string& content : workspacePtr->getWorkspaceContent()) {
                    file << content << endl;
                }
                file <<  endl;
                file<<"wsCommand:"<<endl;
                for (const string& content : workspacePtr->wsCommands) {
                    file << content << endl;
                }
                file <<  endl;
                file.close();
                if (!file) {
                    // 处理文件关闭失败的情况
                    cout<<"backup文件关闭失败"<<endl;
                }
                workspaceCounter++;
            }
            else{
                cout<<"生成备份文件"<<fileName<<"失败"<<endl;
            }
        }
}
/**
 * @brief 用于还原上次保存的工作区内容
 */
vector<WorkSpace*> SessionMemento::getWorkspaces() 
{
    vector<WorkSpace*> Workspaces;
    if (fs::exists(MementoPath) && fs::is_directory(MementoPath)) {
        for (const auto& entry : fs::directory_iterator(MementoPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {

                ifstream file(entry.path().string());
                if (file.is_open()) {
                    string line;
                    //WorkSpace* workspace = nullptr; 
                    while (getline(file, line)) {
                        // 提取文件名
                        //cout<<"get line"<<line;
                        if (line == "filename: ") {
                            
                            getline(file, line);
                            WorkSpace *workspace = new WorkSpace(line);
                           // cout<<"get name"<<workspace->getFileName()<<endl;
                            while (getline(file, line)) {
                                if (line == "content:") {
                                    while (getline(file, line) && !line.empty()&&line != "wsCommand:") {
                                        workspace->workspace_content.push_back(line);
                                    }
                                    // 提取wsCommand
                                    if (line == "wsCommand:") {
                                    while (getline(file, line) && !line.empty()) {
                                        workspace->wsCommands.push_back(line);
                                    }
                                }
                                }
                            }
                            //cout<<"push_back"<<workspace->getFileName()<<endl;
                            workspaces.push_back(workspace);
                        }
                        if (line == "*filename: ") {      
                            getline(file, line);
                            WorkSpace *workspace = new WorkSpace(line);
                           // cout<<"get name"<<workspace->getFileName()<<endl;
                            currentFileName = workspace->getFileName();
                            while (getline(file, line)) {
                                if (line == "content:") {
                                    while (getline(file, line) && !line.empty()&&line != "wsCommand:") {
                                        workspace->workspace_content.push_back(line);
                                    }
                                    // 提取wsCommand
                                    if (line == "wsCommand:") {
                                    while (getline(file, line) && !line.empty()) {
                                        workspace->wsCommands.push_back(line);
                                    }
                                }
                                }
                            }
                            //cout<<"push_back"<<workspace->getFileName()<<endl;
                            workspaces.push_back(workspace);
                        }
                file.close();
                    } 
                }
            }
        }
    }
    clearFolder(MementoPath);//提取之后清空文件夹
    return Workspaces;
}