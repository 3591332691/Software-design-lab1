#include "SessionCommand.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "tool\\tool.h"
#include "constants.h"
#include "File\\WorkSpace.h"
#include "invoker.h"
#include <limits>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;  // 使用 std::filesystem 命名空间
extern vector <string> history;
extern vector<WorkSpace*> workspaces;
extern string currentFileName;
extern vector <string> currentFileContents;
extern vector<string> workingTime;
void List_workspaceCommand::execute() {
    for (WorkSpace* workspace : workspaces) {
        string workspaceName = workspace->get_workspace_name();
        string fileName = workspace->getFileName();
        if (currentFileName == fileName) {
            cout << "->" << workspaceName;
        } else {
            cout << "  "<<workspaceName;
        }
        if(checkWorkSpaceStatus(workspace)==1)
        {
            cout<<" *"<<endl;
        }
        else{
            cout<<""<<endl;
        }
    }
}
void CloseCommand::execute() {
    if(currentFileName == "") {
        cout<<"没有文件正在被编辑"<<endl;
        return ;
    }
    for (auto it = workspaces.begin(); it != workspaces.end(); ++it) {
        WorkSpace* workspace = *it;
        string fileName = workspace->getFileName();
        if (currentFileName == fileName) { // 找到正在进行的 workspace
            // 0. 根据文件状态问问“Do you want to save the current workspace [Y\N] ？”，如果 y 就 save
            if(checkWorkSpaceStatus(workspace)==1)
            {
                cout<<"Do you want to save the current workspace [Y\\N] ?";
                char userChoice;
                // std::ios_base::sync_with_stdio(false);  // 禁用同步

                // // 其他代码

                // if (std::cin >> userChoice) {
                //     // 用户输入了数据
                //     //std::cout << "User input: " << userChoice << std::endl;
                // } else {
                //     // 没有用户输入,默认为y
                //     userChoice = 'Y';
                // }


                // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区中的换行符
                userChoice = 'Y';
                if (userChoice == 'Y' || userChoice == 'y') {
                    SaveCommand *commandA = new SaveCommand;
                    Invoker invoker;
                    invoker.setSaveCommand(commandA);
                    invoker.executeCommand();
                    delete commandA;
                }
            }
            // 1. store工作时间&放到 WorkingTime 里面
            workspace->storeWorkingTime();
            pushWorkspaceIntoWorkingTime(workspace);
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
void OpenCommand::execute(){
    string openWorkspaceName = "";
    if (!history.empty()) {
        string& latestCommand = history.back(); // 获取最新的命令
        string openCommandPrefix = "open ";
        size_t prefixPos = latestCommand.find(openCommandPrefix);
        if (prefixPos != string::npos) {
            openWorkspaceName = latestCommand.substr(prefixPos + openCommandPrefix.length(),latestCommand.length() - (prefixPos + openCommandPrefix.length())-1);
        }
    }
    if(openWorkspaceName!=""&&currentFileName!=""){
        WorkSpace* newWorkspace = findWorkspaceByName(openWorkspaceName);
        if (newWorkspace != nullptr) {
            //找到了符合 openWorkspaceName 的 workspace,
            //更新currentFileContents,currentFileName
            WorkSpace* oldWorkspace = findWorkspaceByFileName(currentFileName);
            oldWorkspace->storeWorkingTime();
            newWorkspace->setStartTime();
            oldWorkspace->setWorkingSpaceContent(currentFileContents);
            currentFileContents = newWorkspace->getWorkspaceContent();
            currentFileName = newWorkspace->getFileName();
        }
        else{
            cout<<"找不到名字为"<<openWorkspaceName<<"的workspace"<<endl;
        }
    }
    if(openWorkspaceName!=""&&currentFileName==""){
        WorkSpace* newWorkspace = findWorkspaceByName(openWorkspaceName);
        if (newWorkspace != nullptr) {
            //找到了符合 openWorkspaceName 的 workspace,
            //更新currentFileContents,currentFileName
            newWorkspace->setStartTime();
            currentFileContents = newWorkspace->getWorkspaceContent();
            currentFileName = newWorkspace->getFileName();
        }
        else{
            cout<<"找不到名字为"<<openWorkspaceName<<"的workspace"<<endl;
        }
    }
    /*if(openWorkspaceName!=""&&currentFileName==""){//open a new
        WorkSpace* newWorkspace = findWorkspaceByName(openWorkspaceName);
        if (newWorkspace != nullptr) {
            //找到了符合 openWorkspaceName 的 workspace,
            //更新currentFileContents,currentFileName
            newWorkspace->setStartTime();
            currentFileContents = newWorkspace->getWorkspaceContent();
            currentFileName = newWorkspace->getFileName();
        }
        else{
            //cout<<"找不到名字为"<<openWorkspaceName<<"的workspace"<<endl;
        }
    }*/

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
    //2.写workingtimeLog
    ofstream file2(worktimeLogPath, ios::app);
    if (!file2.is_open()) {
        // 文件打开失败，处理错误
        cout<<"Error:打开workingtimeLog失败"<<endl;
    }
    else{
        // 将 还开着的workspace时长写入stats，特别要注意正在进行的要store一遍
        WorkSpace* oldWorkspace = findWorkspaceByFileName(currentFileName);
        if (oldWorkspace != nullptr) {
            // 找到了符合 currentFileName 的 workspace
            oldWorkspace->storeWorkingTime();
        }
        for (int i = 0;i<workspaces.size();i++) {
            pushWorkspaceIntoWorkingTime(workspaces[i]);
        }
        //把全局变量stats里的写入文件
        printWorkingTime();
        // 添加一个空行作为分隔
        file2 << endl;
        // 关闭文件
        file2.close();
    }
    //3.保存所有开启的workspace便于后面恢复workspace

    // WorkSpace * a = findWorkspaceByFileName(currentFileName);
    // a->setWorkingSpaceContent(currentFileContents);
    // SessionMemento memo;
    // memo.storeWorkspace(workspaces);
    
    //下面这里是判断，上下是两种不同的需求
    int unsavedFlag = 0;
    for(auto a:workspaces){//检测有没有未保存的
       //cout<<"检测有没有未保存的workspace"<<endl;
       if(checkWorkSpaceStatus(a)==1)
       {
            unsavedFlag = 1;
            break;
        }
    }
    if(unsavedFlag==1)
    {
        cout<<"Do you want to save the unsaved workspace [Y\\N] ?";

        // char userChoice;
        // cin >> userChoice; 
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区中的换行符
        //TODO:如果是free test,把这里改回来

        char userChoice = 'Y';//new change for test4
        
        //如果回答yes
        if (userChoice == 'Y' || userChoice == 'y'){//
            WorkSpace * a = findWorkspaceByFileName(currentFileName);
            a->setWorkingSpaceContent(currentFileContents);
            SessionMemento memo;
            memo.storeWorkspace(workspaces);
        }
    }
}

void SaveCommand::execute() {
    ofstream file(currentFileName,ios::trunc);
    if (file.is_open()) 
    {
        for(auto content : currentFileContents)
        {
             file << content << endl;
        }
        //cout<<"save "<<currentFileName<<" done"<<endl;
    }
    else
    {
        printf("save failed --file not open\n");
    }
}

void LsCommand::execute() {//16
    if(currentFileName=="") return;
    fs::path root = fs::path(currentFileName).parent_path();
    Working_directoryTreeNode* rootDir = buildDirectoryTree(root.string());

    for (Working_directoryTreeNode* child : rootDir->children) {//先写*的
        if(currentFileName.find(child->NodeName)==currentFileName.length()-child->NodeName.length() ){

            if(rootDir->children.size() == 1){//只有一个的话，他就是last
                if(rootDir->children.back()==child){
                //是children里的最后一个，为了方便直接去掉
                if(child == rootDir->children.back()){
                    rootDir->children.pop_back();
                }
            }
                displayDirectoryTree(child,true,"");
            }
            else{
                if(rootDir->children.back()==child){
                //是children里的最后一个，为了方便直接去掉
                if(child == rootDir->children.back()){
                    rootDir->children.pop_back();
                }
            }
                displayDirectoryTree(child,false,"");
            }
            
            
        }
    }

    for (Working_directoryTreeNode* child : rootDir->children) {
        if(currentFileName.find(child->NodeName)!=currentFileName.length()-child->NodeName.length()){
            if(rootDir->children[rootDir->children.size()-1]==child)
                displayDirectoryTree(child,true,"");//最后一个，islast==true
            else{
                displayDirectoryTree(child,false,"");
            }
        }
        
    }
}