#include <iostream>
#include "Command.h"
using namespace std;

int testCommandLoad(){
    string str,filename;
    cin>>str;
    string filename1 = "./testplace/txt.md"
    while(str!=""&&str!="end"){
        if(str.find("create") == 1){//成功获得函数
            filename = str.substr(str.find("create")+8);
        }
    }
}

int main(){
    testCommandLoad();
    return 0;
}