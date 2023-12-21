#include <iostream>
#include <string>
#include <vector>
#include "ContentsCommand.h"
#include "tool\\tool.h"
using namespace std;
extern vector <string> currentFileContents;
extern vector <string> history;
extern vector <string> contentsCommandHistory;
extern string currentFileName;
void insertCommand::insert(int lineNumber, string str){//行数从1开始计算
    int a = lineNumber;
    contentsCommandHistory.push_back("insert "+to_string(lineNumber)+" "+str);
    //把insert history写入workspace的wsCommands
    WorkSpace *w = findWorkspaceByFileName(currentFileName);
    w->wsCommands.push_back("insert "+to_string(lineNumber)+" "+str);
    if((a==1||a==0)&&currentFileContents.size()==0)//这个文件刚被创建  append ahead + insert不加行数
    {
        currentFileContents.push_back(str);
    }
    else if(a==1&&currentFileContents.size()>=1)//文件已有一定内容： append ahead
    {
        currentFileContents.insert(currentFileContents.begin(), str);
    }
    else if (a>currentFileContents.size())//append tail + 指定函数超出范围的情况
    {
        currentFileContents.resize(a);
        currentFileContents[a-1] = str;
    }
    else//指定第几行
    {
        currentFileContents.insert(currentFileContents.begin() + lineNumber-1, str);
    }
}
void deleteCommand::delete_(int n)
{
    if(n>currentFileContents.size()||n<=0)cout<<"找不到第"<<n<<"行"<<endl;
    else{
        string tempCommand = "delete "+to_string(n)+" "+currentFileContents[n-1];
        contentsCommandHistory.push_back(tempCommand);//写入contents Command History
        //history.push_back(getTime()+tempCommand);//写入history
        //把delete history写入workspace的wsCommands
        WorkSpace *w = findWorkspaceByFileName(currentFileName);
        w->wsCommands.push_back(tempCommand);
        for(int i = n-1;i+1<currentFileContents.size();i++)
    {
        currentFileContents[i] = currentFileContents[i+1];
    }
        currentFileContents.pop_back();
        //cout<<"删除了第"<<n<<"行"<<endl;
    }
}
void deleteCommand::delete_(string s)
{
    int temp = 0;
    for(int i = 0; i < currentFileContents.size(); i++){
        int au = currentFileContents[i].find(s);
        if(static_cast<int>(currentFileContents[i].find(s))>=0){
            string tempCommand = "delete "+to_string(i+1)+" "+currentFileContents[i];
            contentsCommandHistory.push_back(tempCommand);
            //把delete history写入workspace的wsCommands
            WorkSpace *w = findWorkspaceByFileName(currentFileName);
            w->wsCommands.push_back(tempCommand);
            delete_(i+1);
            temp = 1;
        }
    }
    if(temp == 0)cout<<"delete error: 找不到"<<s<<endl;
}