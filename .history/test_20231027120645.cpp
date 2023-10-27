#include <iostream>
#include "Command.h"
using namespace std;

int testCommandCreate(){
    string str,filename;
    cin>>str;
    while(str!=""&&str!="end"){
        if(str.find("create") == 1){//成功获得函数
            filename = str.substr(str.find("create")+8);
        }
    }
}

int main(){
    testCommandCreate();
    return 0;
}