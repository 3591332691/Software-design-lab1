#include "SessionCommand.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "constants.h"
#include "File/WorkSpace.h"
using namespace std;
extern vector <string> history;
extern vector<WorkSpace*> workspaces;
extern string currentFileName;
extern vector <string> currentFileContents;
extern vector<string> workingTime;
void List_workspaceCommand::execute() {//TODO:已修改还未save的加*号
    for (WorkSpace* workspace : workspaces) {
        string workspaceName = workspace->get_workspace_name();
        string fileName = workspace->getFileName();
        if (currentFileName == fileName) {
            cout << "->" << workspaceName << endl;
        } else {
            cout << "  "<<workspaceName << endl;
        }
    }
}
void CloseCommand::execute() {
    if(currentFileName == "") {
        cout<<"没有文件正在编辑"<<endl;
        return ;
    }
    for (auto it = workspaces.begin(); it != workspaces.end(); ++it) {
        WorkSpace* workspace = *it;
        string fileName = workspace->getFileName();
        if (currentFileName == fileName) { // 找到正在进行的 workspace
            // 0. 根据文件状态问问“Do you want to save the current workspace [Y\N] ？”，如果 y 就 save
            // 1. store工作时间，放到 stats 里面
            workspace->storeWorkingTime();//TODO:这段可以代码可以复用
            bool found = false; // 标记在workingTime里是否找到了自己
            for (auto it = workingTime.begin(); it != workingTime.end(); ++it) {
                string& timeString = *it;
                size_t spaceIndex = timeString.find(' ');
                if (spaceIndex != string::npos) {
                    string fileName = timeString.substr(0, spaceIndex);
                    if (fileName == workspace->getFileName()) { // 如果在 workingTime 中找到了自己
                        int time = workspace->getWorkingTime();
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
            if (!found) {//如果没找到，
                string newTimeString = workspace->getFileName() + " " + to_string(workspace->getWorkingTime());
                workingTime.push_back(newTimeString);
            }
            // 2. 清空 current
            currentFileName = "";
            currentFileContents.clear();
            // 3. 移除这个 workspace
            workspaces.erase(it);
            delete workspace; // 注意释放内存
            return;
        }
    }
}
void ExitCommand::execute() {
    //1.写historyLog
    ofstream file1(historylogPath, ios::app);
    if (!file1.is_open()) {
        // 文件打开失败，处理错误
        cout<<"Error:打开historyLog失败"<<endl;
    }
    else{
        // 将 history 中的内容逐行写入文件
        for (const string& line : history) {
            file1 << line << endl;
        }

        // 添加一个空行作为分隔
        file1 << endl;

        // 关闭文件
        file1.close();
    }
    //2.TODO:写workingtimeLog,要加一个全局变量stats来记录已被关闭的workspace的工作时长，把还开着的都加到stats里
    ofstream file2(worktimeLogPath, ios::app);
    if (!file2.is_open()) {
        // 文件打开失败，处理错误
        cout<<"Error:打开workingtimeLog失败"<<endl;
    }
    else{
        // 将 还开着的workspace时长写入stats，特别要注意正在进行的要store一遍
        for (int i = 0;i<workspaces.size();i++) {
            
        }
        //把全局变量stats里的写入文件
        // 添加一个空行作为分隔
        file2 << endl;

        // 关闭文件
        file2.close();
    }
}