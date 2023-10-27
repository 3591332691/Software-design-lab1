#include <iostream>
#include <vector>
#include <regex>
#include "Command.h"
#include "invoker.h"
using namespace std;
vector<string> commands;
string currentFileName;
int testCommandLoad(){
    commands.clear();
    string str;
    string filename1 = "C:\\Users\\HUAWEI\\Desktop\\program\\softwareDesign\\testplace\\txt1.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    string filename2 = "../txt1.md";
    str = "load "+filename2+"\n";
    commands.push_back(str);
    string filename3 = "../txt2?.md";
    str = "load "+filename3+"\n";
    commands.push_back(str);
    return 0;
}
int pre_process_command(){

}
int main(){
    testCommandLoad();
    
    return 0;
}