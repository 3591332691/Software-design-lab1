#include <iostream>
#include <fstream>
#include "FileCommand.h"
#include "File\\WorkSpace.h"
using namespace std;
extern string currentFileName;
extern vector <string> currentFileContents;//其实就是外界的workspace contents
extern vector<WorkSpace*> workspaces;
extern int currentWorkSpaceId;
/**
 * @brief invoker_load(C), 用于打开文件并且载入内容到currentFileContents
 */
void mdFile::load() {//只有new才会进来
    //如果这条load命令前面load过文件了,把工作台内容保存在上一个文件工作台里
    if(currentFileName.empty()!=0){//处理旧的workspace
        workspaces[currentWorkSpaceId]->setWorkingSpaceContent(currentFileContents);
        workspaces[currentWorkSpaceId]->storeWorkingTime();
    }
    ifstream file(filename,ios::in);
    if (file.is_open()) 
    {   
        //读取新文件内容到currentFileContents里
        currentFileContents.clear();
        string line;
        while (std::getline(file, line)) {
            currentFileContents.push_back(line);
        }
        file.close();
    } 
    else 
    {
        ofstream create_file (filename);
        create_file.close();
        currentFileContents.clear();
    }
    //更新了currentFileName
    currentFileName = filename;
    //更新workspace id
    currentWorkSpaceId = workspaces.size()-1;
    workspaces[currentWorkSpaceId]->setStartTime();
}
void mdFile::save(){
    ofstream file(currentFileName,ios::trunc);
    if (file.is_open()) 
    {
        for(auto content : currentFileContents)
        {
             file << content << endl;
        }
        cout<<"save "<<currentFileName<<" done"<<endl;
    }
    else
    {
        printf("save failed --file not open\n");
    }

}