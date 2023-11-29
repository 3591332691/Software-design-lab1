#include <vector>
#include<iostream>
#include <time.h>
#include <regex>
#include<string>
#include "tool.h"
#include "File//WorkSpace.h"
using namespace std;
extern vector <string> contentsCommandHistory;
extern vector <string> currentFileContents;
extern vector<WorkSpace*> workspaces;
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
    cout<<"show current file contents"<<endl;
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