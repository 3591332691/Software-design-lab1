#include <vector>
#include<iostream>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <regex>
#include<string>
#include "tool.h"
#include "File//WorkSpace.h"
#include "constants.h"
using namespace std;
namespace fs = std::filesystem;  // 使用 std::filesystem 命名空间
extern string currentFileName;
extern vector <string> contentsCommandHistory;
extern vector <string> currentFileContents;
extern vector<WorkSpace*> workspaces;
extern vector<string> workingTime;
vector<string> commandsSummary = {
    "load","save","insert","append-","delete",
    "undo","redo","list-tree","list-workspace","dir-tree",
    "history","stats","list","open","close",
    "exit","ls","start"
};
/**
 * @brief 用于输出两个log里的时间
 */
string getTime(){
    time_t t = time(0); 
    char tmp[32];
    strftime(tmp, sizeof(tmp), "%Y%m%d %H:%M:%S ",localtime(&t)); 
    return string(tmp);
}
/**
 * @brief 用于判断输入的是哪个命令或者不是命令(error)
 */
int checkWhichCommand(string a){
    for(int i = 0;i<commandsSummary.size();i++){
        if(a.find(commandsSummary[i])==0)return i;
    }
    return -1;
}
/**
 * @brief 用于判断输入的是几级标题或者是正文
 */
int find_the_level(string line)
{
    regex pattern("^(#+ )");
    smatch match;
    if (regex_search(line, match, pattern)) {
        string matchedString = match.str();
        return matchedString.length() - 2;  // 减去空格和 #
    }
    return 0;
};
/**
 * @brief 展示当前文档(工作区的)内容
 */
void showCurrentFileContents(){
    if(currentFileName=="") return ;
    cout<<"show "<<currentFileName;
    WorkSpace* a = findWorkspaceByFileName(currentFileName);
    if(checkWorkSpaceStatus(a)==1)
    {
        cout<<"*"<<endl;
    }
    else
    {
        printf("\n");
    }

    for(auto a:currentFileContents){
        cout<<a<<endl;
    }
}
/**
 * @brief 展示“内容改变命令” 栈，用于redo和undo
 */
void showContentsCommandHistory(){
cout<<"show Contents Command History"<<endl;
    for(auto a:contentsCommandHistory){
        cout<<a<<endl;
    }
}
/**
 * @brief 检查是否有同名的workspace
 */
bool checkWorkSpaceNameOccupied(string workspace_name){
    for (WorkSpace* workspace : workspaces) {
        if (workspace->get_workspace_name() == workspace_name) {
            return true; // 发现同名的 workspace
        }
    }
    return false; // 没有同名的 workspace
}
/**
 * @brief 根据workspaceName来找到Workspace
 * @return 如果没有找到符合条件的 workspace，则返回 nullptr
 */
WorkSpace* findWorkspaceByName(const std::string& workspaceName) {
    for (WorkSpace* workspace : workspaces) {
        if (workspace->get_workspace_name() == workspaceName) {
            return workspace;
        }
    }
    return nullptr; // 如果没有找到符合条件的 workspace，则返回 nullptr
}

/**
 * @brief 根据fileName来找到Workspace
 * @return 如果没有找到符合条件的 workspace，则返回 nullptr
 */
WorkSpace* findWorkspaceByFileName(const std::string& fileName) {
    for (WorkSpace* workspace : workspaces) {
        if (workspace->getFileName() == fileName) {
            return workspace;
        }
    }
    return nullptr; // 如果没有找到符合条件的 workspace，则返回 nullptr
}
/**
 * @brief 把一个workspace的working time写入WorkingTime统计
 * @param a 要写入Working Time的workspace
 */
void pushWorkspaceIntoWorkingTime(WorkSpace* a){
            bool found = false; // 标记在workingTime里是否找到了自己
            for (auto it = workingTime.begin(); it != workingTime.end(); ++it) {
                string& timeString = *it;
                size_t spaceIndex = timeString.find(' ');
                if (spaceIndex != string::npos) {
                    string fileName = timeString.substr(0, spaceIndex);
                    if (fileName == a->getFileName()) { // 如果在 workingTime 中找到了自己
                        int time = a->getWorkingTime();
                        size_t digitIndex = timeString.find_first_of("0123456789", spaceIndex);
                        if (digitIndex != string::npos) {
                            int currentValue = stoi(timeString.substr(digitIndex));
                            int newValue = currentValue + time;
                            timeString = fileName + " " + to_string(newValue); // 改变后面的分钟数
                        }
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {//如果没找到，给workingTime新的坑
                string newTimeString = a->getFileName() + " " + to_string(a->getWorkingTime());
                workingTime.push_back(newTimeString);
            }
}

/**
 * @brief 按格式把WorkingTime输出到worktimeLog.txt
 */
void printWorkingTime() {
    ofstream outputFile(worktimeLogPath,ios::app); // 打开输出文件
    if (outputFile.is_open()) { // 检查文件是否成功打开
        for (const string& timeString : workingTime) {
            istringstream iss(timeString);
            string fileName;
            int minutes;
            if (iss >> fileName >> minutes) {
                int hours = minutes / 60;
                minutes = minutes % 60;
                outputFile << fileName << " ";
                if (hours > 0) {
                    outputFile << hours << " 小时 ";
                }
                outputFile << minutes << " 分钟" << endl;
            }
        }
        outputFile.close(); // 关闭文件
    } else {
        cout << "无法打开文件: " << worktimeLogPath << endl;
    }
}

/**
 * @brief 检查一个输入的workSpace*是什么状态
 * @return 1是修改过未保存  0是其他状态
 */
int  checkWorkSpaceStatus(WorkSpace *a) {
    if(a->wsCommands.size() == 0)
    {//未修改状态
        return 0;
    }
    if(a->wsCommands.size()>0&&a->wsCommands.back()!="save")
    {//修改过未保存
        return 1;
    }
    return 0;
}

/**
 * @brief ls 命令的辅助函数，用于创建树
 * @param path 当前文件的父目录
 */
Working_directoryTreeNode* buildDirectoryTree(const string& path, Working_directoryTreeNode* parent) {
    //创建root--代表父目录
    Working_directoryTreeNode* node = new Working_directoryTreeNode;
    node->NodeName = fs::path(path).filename().string();
    node->level = parent ? parent->level + 1 : 0;
    node->parent = parent;
    //
    if (fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            Working_directoryTreeNode* childNode = buildDirectoryTree(entry.path().string(), node);
            node->children.push_back(childNode);
        }
    } else {
        // 处理文件节点
        node->children.push_back(nullptr);  // 将文件节点的子节点指针设置为 nullptr
    }
    return node;
}
/**
 * @brief ls 命令的辅助函数，用于展示树
 * @param node 创建出来的父目录node
 */
void displayDirectoryTree(Working_directoryTreeNode* node, bool isLastChild, string indent) {
    if (node->NodeName!=""&&node) {
        cout << indent;
        if (node->level > 0) {
            std::cout << (isLastChild ? "└── " : "├── ");
        }
        cout << node->NodeName;
        if(currentFileName.find( node->NodeName)==currentFileName.length() -node->NodeName.length() )
        {
            cout<<" *"<<endl;
            return ;
        }
        cout<<endl;
        string childIndent = indent + (isLastChild ? "    " : "│   ");
        for (size_t i = 0; i < node->children.size(); ++i) {
            bool isLast = (i == node->children.size() - 1);
            // 添加条件检查，确保 node 不为空
            if (node->children[i]) {
                displayDirectoryTree(node->children[i], isLast, childIndent);
            }
        }
    }
}


void clearFolder(const std::string& folderPath) {
    try {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (fs::is_directory(entry)) {
                clearFolder(entry.path().string());  // 递归清空子文件夹
                fs::remove(entry);  // 删除子文件夹
            } else {
                fs::remove(entry);  // 删除文件
            }
        }
    } catch (const std::exception& e) {
        std::cout << "清空文件夹内容时出错: " << e.what() << std::endl;
    }
}