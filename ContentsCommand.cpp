#include <iostream>
#include <string>
#include <vector>
#include "ContentsCommand.h"
#include "tool.h"
using namespace std;
extern vector <string> currentFileContents;
extern vector <string> history;
void insertCommand::insert(int lineNumber, string str){
    int a = lineNumber;
    if(lineNumber ==1&&currentFileContents.size()==1&&currentFileContents[0] =="")
    {
        currentFileContents[0] = str;
    }
    else if (a>currentFileContents.size())
    {
        currentFileContents.resize(a);
        currentFileContents[a-1] = str;
    }
    else
    currentFileContents.insert(currentFileContents.begin() + lineNumber-1, str);
}
void deleteCommand::delete_(int n)
{
    if(n>currentFileContents.size()||n<=0)cout<<"找不到第"<<n<<"行"<<endl;
    else{
        string tempCommand = "delete "+to_string(n)+" "+currentFileContents[n-1];
        history.push_back(getTime()+tempCommand);//写入history
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
            //string tempCommand = "delete "+to_string(i+1)+" "+currentFileContents[i];
            //history.push_back(getTime()+tempCommand);//写入history
            //cout<<au<<endl;
            delete_(i+1);
            temp = 1;
        }
    }
    if(temp == 0)cout<<"找不到"<<s<<endl;
}