#include <vector>
#include<iostream>
#include <time.h>
#include <regex>
#include<string>
#include "tool.h"
using namespace std;
extern vector <string> contentsCommandHistory;
extern vector <string> currentFileContents;
vector<string> commandsSummary = {"load","save","insert","append-","delete","undo","redo","list-tree",
"list","dir-tree","history"};
/// @brief 
/// @return 
string getTime(){
    time_t t = time(0); 
    char tmp[32];
    strftime(tmp, sizeof(tmp), "%Y%m%d %H:%M:%S ",localtime(&t)); 
    return string(tmp);
}
int checkWhichCommand(string a){
    for(int i = 0;i<commandsSummary.size();i++){
        if(a.find(commandsSummary[i])==0)return i;
    }
    return -1;
}
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
void showCurrentFileContents(){
    cout<<"show current file contents"<<endl;
    for(auto a:currentFileContents){
        cout<<a<<endl;
    }
}
void showContentsCommandHistory(){
cout<<"show Contents Command History"<<endl;
    for(auto a:contentsCommandHistory){
        cout<<a<<endl;
    }
}