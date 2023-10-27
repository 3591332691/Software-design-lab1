#include <iostream>
#include <string>
#include <vector>
#include "ContentsCommand.h"
using namespace std;
extern vector <string> currentFileContents;

void insertCommand::insert(int lineNumber, string str){
    currentFileContents.insert(currentFileContents.begin() + lineNumber, str);
}
void insertCommand::append_head(string str){
    insert(0,str);
}
void insertCommand::append_tail(string str){
    insert(currentFileContents.size())
}

void deleteCommand::delete_(int n)
{
    for(int i = n-1;i<currentFileContents.size();i++)
    {
        currentFileContents[i] = currentFileContents[i+1];
    }
    currentFileContents.pop_back();
}
void deleteCommand::delete_(string s)
{
    vector<string> result;
}