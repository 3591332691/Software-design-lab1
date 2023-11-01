#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <ctype.h>
#include "FileCommand.h"
#include "invoker.h"
#include "ContentsCommand.h"
#include "tool.h"
using namespace std;
vector<string> commands; // for test
string currentFileName = "";
vector<string> currentFileContents;
vector<string> history;
int testCommand(vector<string> commands)
{
    for (auto command : commands)
    {
        switch (checkWhichCommand(command))
        {
        case 0:
        {
            regex pattern("^([a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+,)*[a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+$");
            regex pattern1("^[\\.]{1,2}((/){1}[\\w]+[\\.]{0,1}[\\w]+)+$");
            string filePath = command.substr(command.find("load") + 5);
            filePath = filePath.substr(0, filePath.length() - 1);
            if ((regex_match(filePath, pattern) || regex_match(filePath, pattern1)) && filePath.find(".md") == (filePath.length() - 3))
            {
                FileCommand *commandA = new mdFile(filePath);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeLoadCommand();
                cout << "打开了文件" << filePath << endl;
                currentFileName = filePath;
                delete commandA;
                history.push_back(getTime() + command);
            }
            else
            {
                cout << "路径" << filePath << "有非法字符" << endl;
            }
            break;
        }
        case 1:
        {
            if (currentFileName == "")
            {
                cout << "save failed --not preload" << endl;
            }
            else
            {
                FileCommand *commandA = new mdFile(currentFileName);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeSaveCommand();
                delete commandA;
                history.push_back(getTime() + command);
                currentFileName = "";
            }
            break;
        }
        case 2:
        {
            int pos = command.find_first_of(" ");
            command = command.substr(pos + 1);
            int tempFlag = 0;
            for (auto c : command) // 1_n->flag = 1;n->flag = -1;___\n->flag = 0;
            {
                if (c <= '9' && c >= '0')
                    tempFlag = 1;
                else if (c == ' ')
                {
                    break;
                }
                else
                {
                    tempFlag = -1;
                    break;
                }
            }
            if (tempFlag == 1) // insert到第number_line行
            {
                int number_line = stoi(command.substr(0, command.find_first_of(" ")));
                string text = command.substr(command.find_first_of(" ") + 1);
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(number_line, text);
                delete commandA;
                cout << "##Command被重写入history为" << command << endl;
                history.push_back(getTime() + command);
            }
            else if (tempFlag == -1) // insert到末尾
            {
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(currentFileContents.size(), command);
                delete commandA;
                command = "insert " + to_string(currentFileContents.size()) + " " + command;
                cout << "##Command被重写入history为" << command << endl;
                history.push_back(getTime() + command);
            }
            else
            {
                printf("insert 格式不正确");
            }
            break;
        }
        case 3:
        {
            insertCommand *commandA = new insertCommand;
            Invoker invoker;
            invoker.setInsertCommand(commandA);
            if (command.find("append-head") == 0)
            {
                history.push_back(getTime() + command);
                command = command.substr(command.find_first_of(" ") + 1);
                invoker.executeInsertCommand(0, command);
            }
            else
            {
                history.push_back(getTime() + command);
                command = command.substr(command.find_first_of(" ") + 1);
                invoker.executeInsertCommand(currentFileName.size(), command);
            }
            delete commandA;
            break;
        }
        case 4:
        {
            command = command.substr(command.find_first_of(" ") + 1);
            command.erase(command.find('\n'), 1);
            deleteCommand *commandA = new deleteCommand();
            Invoker invoker;
            invoker.setDeleteCommand(commandA);
            int temp = 0;
            for (auto c : command)
            {
                if (c <= '9' && c >= '0')
                {
                    ;
                }
                else
                {
                    invoker.executeDeleteCommand(command);
                    temp = 1;
                    break;
                }
            }
            if (temp == 0 && stoi(command) > 0)
                invoker.executeDeleteCommand(stoi(command));
            delete commandA;
            break;
        }
        case 5:
        {
            history.push_back(getTime() + command);
            if (history[history.size() - 1].find("insert"))
            {
                string a = history[history.size() - 1];
                a = a.substr(a.find(" ") + 1, a.find(" ", a.find(" ") + 1) - a.find(" "));//a是第几行
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(stoi(a));//delete自动写了history
            }
            else if (history[history.size() - 1].find("append-head"))
            {
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(1);//delete自动写了history
            }
            else if (history[history.size() - 1].find("append-tail"))
            {
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(currentFileContents.size());//delete自动写了history
            }
            else if (history[history.size() - 1].find("delete"))
            {
                string inner_process = history[history.size() - 1];
                inner_process = inner_process.substr(inner_process.find("delete")+6);
                int number_line = stoi(inner_process.substr(0, inner_process.find_first_of(" ")));//number是代表第几行
                string text = inner_process.substr(command.find_first_of(" ") + 1);//text是被删掉的内容
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(number_line, text);
                delete commandA;
                inner_process = "insert "+inner_process;//这里变成undo实际上执行的操作
                history.push_back(getTime() +"#undo-operation: "+ inner_process);
            }
            else
            {
                cout << "您只能撤销插入和删除操作";
                history.pop_back();
            }
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }
        default:
        {
            cout << "未识别出正确命令" << endl;
            break;
        }
        }
    }
    return 0;
}
int pre_process_test(vector<string> commands)
{
    for (auto command : commands)
    {
        if (command.find("load") == 0)
        {
            regex pattern("^([a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+,)*[a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+$");
            regex pattern1("^[\\.]{1,2}((/){1}[\\w]+[\\.]{0,1}[\\w]+)+$");
            string filePath = command.substr(command.find("load") + 5);
            filePath = filePath.substr(0, filePath.length() - 1);
            if ((regex_match(filePath, pattern) || regex_match(filePath, pattern1)) && filePath.find(".md") == (filePath.length() - 3))
            {
                FileCommand *commandA = new mdFile(filePath);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeLoadCommand();
                cout << "打开了文件" << filePath << endl;
                currentFileName = filePath;
                delete commandA;
                history.push_back(getTime() + command);
            }
            else
            {
                cout << "路径" << filePath << "有非法字符" << endl;
            }
        }
        else if (command.find("save") == 0)
        {
            if (currentFileName == "")
            {
                cout << "save failed --not preload" << endl;
            }
            else
            {
                FileCommand *commandA = new mdFile(currentFileName);
                Invoker invoker;
                invoker.setFileCommand(commandA);
                invoker.executeSaveCommand();
                delete commandA;
                history.push_back(getTime() + command);
                currentFileName = "";
            }
        }
        else if (command.find("insert") == 0)
        {
            int pos = command.find_first_of(" ");
            command = command.substr(pos + 1);
            int tempFlag = 0;
            for (auto c : command) // 1_n->flag = 1;n->flag = -1;___\n->flag = 0;
            {
                if (c <= '9' && c >= '0')
                    tempFlag = 1;
                else if (c == ' ')
                {
                    break;
                }
                else
                {
                    tempFlag = -1;
                    break;
                }
            }
            if (tempFlag == 1) // insert到第number_line行
            {
                int number_line = stoi(command.substr(0, command.find_first_of(" ")));
                string text = command.substr(command.find_first_of(" ") + 1);
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(number_line, text);
                delete commandA;
                command = "insert " + to_string(number_line) + " " + text;
                cout << "##Command被重写入history为" << command << endl;
                history.push_back(getTime() + command);
            }
            else if (tempFlag == -1) // insert到末尾
            {
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(currentFileContents.size(), command);
                delete commandA;
                command = "insert " + to_string(currentFileContents.size()) + " " + command;
                cout << "##Command被重写入history为" << command << endl;
                history.push_back(getTime() + command);
            }
            else
            {
                printf("insert 格式不正确");
            }
        }
        else if (command.find("append-head") == 0 || command.find("append-tail") == 0)
        {

            insertCommand *commandA = new insertCommand;
            Invoker invoker;
            invoker.setInsertCommand(commandA);
            if (command.find("append-head") == 0)
            {
                history.push_back(getTime() + command);
                command = command.substr(command.find_first_of(" ") + 1);
                invoker.executeInsertCommand(1, command);
            }
            else
            {
                history.push_back(getTime() + command);
                command = command.substr(command.find_first_of(" ") + 1);
                invoker.executeInsertCommand(currentFileContents.size()+1, command);
            }
            delete commandA;
        }
        else if (command.find("delete") == 0)
        {
            command = command.substr(command.find_first_of(" ") + 1);
            deleteCommand *commandA = new deleteCommand();
            Invoker invoker;
            invoker.setDeleteCommand(commandA);
            int temp = 0;
            for (auto c : command)
            {
                if (c <= '9' && c >= '0')
                {
                    ;
                }
                else
                {
                    invoker.executeDeleteCommand(command);
                    temp = 1;
                    break;
                }
            }
            if (temp == 0 && stoi(command) > 0)
                invoker.executeDeleteCommand(stoi(command));
            delete commandA;
        }
        else if (command.find("undo") == 0)
        {
            history.push_back(getTime() + command);
            if (history[history.size() - 2].find("insert ")==18)
            {
                string a = history[history.size() - 2];
                int temp1 = a.find("insert ")+7;
                a = a.substr(temp1);
                a = a.substr(0,a.find(" "));//a是表示第几行
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(stoi(a));//delete自动写了history
            }
            else if (history[history.size() - 2].find("append-head")==18)
            {
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(1);//delete自动写了history
            }
            else if (history[history.size() - 2].find("append-tail")==18)
            {
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(currentFileContents.size());//delete自动写了history
            }
            else if (history[history.size() - 2].find("delete")==18)
            {
                string inner_process = history[history.size() - 2];
                inner_process = inner_process.substr(inner_process.find("delete")+7);
                int number_line = stoi(inner_process.substr(0, inner_process.find_first_of(" ")));//number是代表第几行
                string text = inner_process.substr(inner_process.find_first_of(" ")+1);//text是被删掉的内容
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(number_line, text);
                delete commandA;
                inner_process = "insert "+inner_process;//这里变成undo实际上执行的操作
                history.push_back(getTime() + inner_process);
            }
            else
            {
                cout << "您只能撤销插入和删除操作"<<endl;
                history.pop_back();//删掉的是之前写的 undo 的history,因为这个undo并没有执行
            }
        }
        else if (command.find("redo") == 0)
        {
            if(history[history.size()-2].find("undo")==18){
                history.push_back(getTime() + command);
                if (history[history.size() - 2].find("insert ")==18)
                {
                    string a = history[history.size() - 2];
                    int temp1 = a.find("insert ")+7;
                    a = a.substr(temp1);
                    a = a.substr(0,a.find(" "));//a是表示第几行
                    deleteCommand *commandA = new deleteCommand();
                    Invoker invoker;
                    invoker.setDeleteCommand(commandA);
                    invoker.executeDeleteCommand(stoi(a));//delete自动写了history
                }
                else if (history[history.size() - 2].find("delete")==18)
                {
                    string inner_process = history[history.size() - 2];
                    inner_process = inner_process.substr(inner_process.find("delete")+7);
                    int number_line = stoi(inner_process.substr(0, inner_process.find_first_of(" ")));//number是代表第几行
                    string text = inner_process.substr(inner_process.find_first_of(" ")+1);//text是被删掉的内容
                    insertCommand *commandA = new insertCommand;
                    Invoker invoker;
                    invoker.setInsertCommand(commandA);
                    invoker.executeInsertCommand(number_line, text);
                    delete commandA;
                    inner_process = "insert "+inner_process;//这里变成undo实际上执行的操作
                    history.push_back(getTime() + inner_process);
                }
            }
        }
    }
    return 0;
}

int testCommandLoad()
{
    commands.clear();
    string str;
    string filename1 = "C:\\Users\\HUAWEI\\Desktop\\program\\softwareDesign\\testplace\\txt1.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    string filename2 = "../txt1.md";
    str = "load " + filename2 + "\n";
    commands.push_back(str);
    string filename3 = "../txt2?.md";
    str = "load " + filename3 + "\n";
    commands.push_back(str);
    pre_process_test(commands);
    return 0;
}
int testCommandSave()
{
    commands.clear();
    string str;
    string filename1 = "C:\\Users\\HUAWEI\\Desktop\\program\\softwareDesign\\testplace\\txt.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    str = "save " + filename1 + "\n";
    commands.push_back(str);
    pre_process_test(commands);
    return 0;
}
int testCommandInsert()
{
    commands.clear();
    string str;
    string filename1 = "../testplace/txt.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    str = "insert 12 ###aaaaaaa\n";
    commands.push_back(str);
    str = "insert the end \n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    pre_process_test(commands);
    return 0;
}
int testCommandAppend()
{
    commands.clear();
    string str;
    string filename1 = "../testplace/txt.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    str = "append-head to be the head\n";
    commands.push_back(str);
    str = "append-tail to be the tail \n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    pre_process_test(commands);
    return 0;
}
int testCommandDelete()
{
    commands.clear();
    string str;
    string filename1 = "../testplace/txt.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    str = "delete 5\n";
    commands.push_back(str);
    str = "delete pa5\n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    pre_process_test(commands);
    return 0;
}
int testCommandUndo(){
    commands.clear();
    string str;
    string filename1 = "../testplace/txt.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    str = "append-head to be the head";
    commands.push_back(str);
    str = "undo \n";
    commands.push_back(str);
    str = "redo \n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    pre_process_test(commands);
    return 0;
}
int testCommandList()
{
    return 0;
}
int freeTest()
{
    string input;
    while (cin >> input && input != "end")
    {
        commands.push_back(input);
        pre_process_test(commands);
    }
    return 0;
}
int initial()
{
    commands.clear();
    currentFileName = "";
    currentFileContents.clear();
    history.clear();
    return 0;
}
int main()
{
    // testCommandLoad();
    // testCommandSave();
    // testCommandInsert();
    // testCommandAppend();
    // testCommandDelete();
    initial();
    testCommandUndo();
    return 0;
}