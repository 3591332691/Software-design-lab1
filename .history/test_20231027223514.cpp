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
    string filename1 = "C:\\Users\\HUAWEI\\Desktop\\program\\softwareDesign\\testplace\\txt.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    string filename2 = "../txt1.md";
    str = "load "+filename1+"\n";
    return 0;
}

int main(){
    testCommandLoad();
    for (auto command : commands)
    {
        cout << command << endl;
        if (command.find("load") == 0)
        {   //TODO:to check the address
            regex pattern("^([a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+,)*[a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+$");
            command = command.substr(command.find("load")+5);
            command = command.substr(0,command.length()-1);
            if(regex_match(command, pattern)&&command.find(".md")==(command.length()-3))
            {
                FileCommand* commandA = new mdFile(command);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeLoadCommand();
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