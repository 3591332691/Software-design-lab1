#include <iostream>
#include <string>
#include <vector>
#include "ContentsCommand.h"
using namespace std;
extern vector <string> currentFileContents;

void insertCommand::insert(int lineNumber, string str){
    if (lineNumber>currentFileContents.size())currentFileContents.reserve(lineNumber);
    currentFileContents.insert(currentFileContents.begin() + lineNumber, str);
}
void deleteCommand::delete_(int n)
{
    if(n>currentFileContents.size()||n<=0)cout<<"找不到第"<<n<<"行"<<endl;
    else{
        for(int i = n-1;i+1<currentFileContents.size();i++)
    {
        currentFileContents[i] = currentFileContents[i+1];
    }
        currentFileContents.pop_back();
        cout<<"删除了第"<<n<<"行"<<endl;
    }
}
void deleteCommand::delete_(string s)
{
    int temp = 0;
    for(int i = 0; i < currentFileContents.size(); i++){
        if(s == currentFileContents[i]){
            delete_(i+1);
            temp = 1;
        }
    }
    if(temp == 0)cout<<"找不到"<<s<<endl;
}