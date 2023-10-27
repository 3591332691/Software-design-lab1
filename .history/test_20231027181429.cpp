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
    string filename1 = "./testplace/txt.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);

}

int main(){
    testCommandLoad();
    for (auto command : commands)
    {
        cout << command << endl;
        if (command.find("load") == 0)
        {   //TODO:to check the address
            regex pattern("^[a-zA-Z0-9_./\\\\]+$");
            command = command.substr(command.find("load")+1);
            if(regex_match(command, pattern))
            FileCommand* commandA = new mdFile(command);
            Invoker invoker;
            invoker.setCommand(commandA);
            invoker.executeCommand();
        }
    }
    return 0;
}