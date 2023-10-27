#include <iostream>
#include <vector>
#include <regex>
#include "Command.h"
#include "invoker.h"
using namespace std;
vector<string> commands;
int testCommandLoad(){
    commands.clear();
    string str;
    string filename1 = "C:\\Users\\HUAWEI\\Desktop\\program\\softwareDesign\\testplace\\txt1.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    string filename2 = "../txt1.md";
    str = "load "+filename2+"\n";
    commands.push_back(str);
    return 0;
}

int main(){
    testCommandLoad();
    for (auto command : commands)
    {
        if (command.find("load") == 0)
        {   //TODO:to check the address
            regex pattern("^([a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+,)*[a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+$");
            regex pattern1("^[\\.]{1,2}((/){1}[\\w]+[\\.]{0,1}[\\w]+)+$");
            command = command.substr(command.find("load")+5);
            command = command.substr(0,command.length()-1);
            if((regex_match(command, pattern)||regex_match(command, pattern1))&&command.find(".md")==(command.length()-3))
            {
                FileCommand* commandA = new mdFile(command);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeLoadCommand();
                cout<<"打开了文件"<<command<<endl;
                delete commandA;
            }
            else
            {
                cout<<"路径有非法字符"<<endl;
            }
            
        }
    }
    return 0;
}