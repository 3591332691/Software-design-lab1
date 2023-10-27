#include <iostream>
#include <vector>
#include "Command.h"
using namespace std;
vector<string> commands;
int testCommandLoad(){
    commands.clear();
    string str,filename;
    string filename1 = "./testplace/txt.md";
    str = "load "+filename1+"\n";
}

int main(){
    testCommandLoad();
    while(str!=""&&str!="end"){
    if(str.find("create") == 1){//成功获得函数
        filename = str.substr(str.find("create")+8);
    }
    }
    return 0;
}