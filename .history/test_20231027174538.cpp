#include <iostream>
#include <vector>
#include "Command.h"
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
        {
            Command* commandA = new mdFile();
        }
    }
    return 0;
}