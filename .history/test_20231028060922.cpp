#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <ctype.h>
#include "FileCommand.h"
#include "invoker.h"
#include "ContentsCommand.h"
using namespace std;
vector<string> commands;
string currentFileName;
vector <string> currentFileContents;

int pre_process_test(){
    for (auto command : commands)
    {
        if (command.find("load") == 0)
        {   
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
                currentFileName = command;
                delete commandA;
            }
            else
            {
                cout<<"路径"<<command<<"有非法字符"<<endl;
            } 
        }
        else if(command.find("save") == 0)
        {
            FileCommand* commandA = new mdFile(currentFileName);
            Invoker invoker;
            invoker.setFileCommand(commandA);
            invoker.executeSaveCommand();
            delete commandA;
        }
        else if(command.find("insert") == 0)
        {
            int pos = command.find_first_of(" ");
            command = command.substr(pos+1);
            int tempFlag = 0;
            for(auto c : command)//1_n->flag = 1;n->flag = -1;___\n->flag = 0;
            {
                if(c<='9'&&c>='0')tempFlag = 1;
                else if(c == ' '){break;}
                else {tempFlag = -1;break;}
                
            }
            if(tempFlag == 1)
            {
                int number_line = stoi(command.substr(0,command.find_first_of(" ")));
                command = command.substr(command.find_first_of(" ")+1);
                insertCommand* commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(number_line,command);
                delete commandA;
            }
            else if(tempFlag == -1)
            {
                insertCommand* commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(currentFileContents.size(),command);
                delete commandA;
            }
            else
            {
                printf("insert 格式不正确");
            }
        }
        else if(command.find("append_head") == 0||command.find("append_tail") == 0)
        {
            
            insertCommand* commandA = new insertCommand;
            Invoker invoker;
            invoker.setInsertCommand(commandA);
            if(command.find("append_head")== 0)
            {
                command = command.substr(command.find_first_of(" ")+1);
            invoker.executeInsertCommand(1,command);
            }
            else
            {
                command = command.substr(command.find_first_of(" ")+1);
                invoker.executeInsertCommand(currentFileName.size(),command);
            }
            
            delete commandA;
        }
    }
    return 0;
}

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
    pre_process_test();
    return 0;
}
int testCommandSave(){
    commands.clear();
    string str;
    string filename1 = "C:\\Users\\HUAWEI\\Desktop\\program\\softwareDesign\\testplace\\txt.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    str = "save "+filename1+"\n";
    commands.push_back(str);
    pre_process_test();
    return 0;
}
int testCommandInsert(){
    commands.clear();
    string str;
    string filename1 = "../testplace/txt.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    str = "insert 12 ###aaaaaaa\n";
    commands.push_back(str);
    str = "insert the end \n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    pre_process_test();
    return 0;
}
int testCommandAppend(){
    commands.clear();
    string str;
    string filename1 = "../testplace/txt.md";
    str = "load "+filename1+"\n";
    commands.push_back(str);
    str = "append-head to be the head\n";
    commands.push_back(str);
    str = "append_tail to be the tail \n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    pre_process_test();
    return 0;
}
int main(){
    //testCommandLoad();
    //testCommandSave();
    //testCommandInsert();
    testCommandAppend();
    commands.clear();
    return 0;
}