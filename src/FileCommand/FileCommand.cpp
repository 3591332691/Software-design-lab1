#include <iostream>
#include <fstream>
#include "FileCommand.h"
#include "File\\WorkSpace.h"
#include "tool\\tool.h"
using namespace std;
extern string currentFileName;
extern vector <string> currentFileContents;//其实就是外界的workspace contents
extern vector<WorkSpace*> workspaces;
/**
 * @brief invoker_load(C), 用于打开文件并且载入内容到currentFileContents
 */
void mdFile::load() {//只有new才会进来
    //如果这条load命令前面load过文件了,把工作台内容保存在上一个文件工作台里
    if(!currentFileName.empty()){//处理旧的workspace
        WorkSpace *b = findWorkspaceByFileName(currentFileName);
        b->setWorkingSpaceContent(currentFileContents);
        b->storeWorkingTime();
    }
    ifstream file(filename,ios::in);
    if (file.is_open()) 
    {
        currentFileContents.clear();
        string line;
        while (std::getline(file, line)) {
            currentFileContents.push_back(line);
        }
        file.close();
        //cout << "打开了文件" << filename << endl;
    } 
    else 
    {
        ofstream create_file(filename);
        if (create_file.good()) {
            cout << "文件创建成功" << endl;
        } else {
            cout << "文件创建失败" << endl;
        }
        create_file.close();
        currentFileContents.clear();
    }
    //更新了currentFileName
    currentFileName = filename;
    //更新workspace start time
    WorkSpace *a = findWorkspaceByFileName(currentFileName);
    a->setStartTime();
}
void mdFile::save(){
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