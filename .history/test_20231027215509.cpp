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
    string filename1 = "C:\Users\HUAWEI\Desktop\program\softwareDesign\testplace";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    return 0;
}

int main(){
    testCommandLoad();
    for (auto command : commands)
    {
        cout << command << endl;
        if (command.find("load") == 0)
        {   //TODO:to check the address
            regex pattern("^[a-zA-Z]:([\\\\/][^\\s\\\\/:*?<>\"|][^\\\\/:*?<>\"|]*)+$");
            command = command.substr(command.find("load")+5);
            cout<<command << endl;
            if(regex_match(command, pattern))
            {
                FileCommand* commandA = new mdFile(command);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeLoadCommand();
            }
            else
            {
                cout<<"路径有非法字符"<<endl;
            }
        }
    }
    return 0;
}