#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "FileCommand\\FileCommand.h"
#include "invoker.h"
#include "ContentsCommand\\ContentsCommand.h"
#include "tool\\tool.h"
#include "CommandParser.h"
#include "File\\WorkSpace.h"
using namespace std;
extern vector <string> currentFileContents;
extern vector <string> history;
extern string currentFileName;
extern vector <string> contentsCommandHistory;
extern vector<WorkSpace*> workspaces;
extern int currentWorkSpaceId;
/**
 * @brief 解析以load开头的命令，调用invoker执行
 */
void CommandParser::CommandParseLoad(string command){
            regex pattern("^([a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+,)*[a-zA-Z]:(([\\\\/])[^\\\\/:*?<>|]+)*([\\\\/])[^\\\\/:*?<>|]+\\.[^\\\\/:*?<>|]+$");
            regex pattern1("^[\\.]{1,2}((/){1}[\\w]+[\\.]{0,1}[\\w]+)+$");
            regex pattern2("^[\\w\\-]+\\.[a-zA-Z]{2,4}$");
            string filePath = command.substr(command.find("load") + 5);
            int a = filePath.find('\n');
            if(a>0)
            {
                filePath = filePath.substr(0, filePath.length() - 1);
            }
            if ((regex_match(filePath, pattern) || regex_match(filePath, pattern1)||regex_match(filePath, pattern2)) && filePath.find(".md") == (filePath.length() - 3))
            {
                //检查workspace是否重复
                WorkSpace* temp = new WorkSpace(filePath);
                if(!checkWorkSpaceNameOccupied(temp->get_workspace_name())){//如果名字未被占用
                    //1.workspace加入workspaces里
                    workspaces.push_back(temp);
                    //“后面一定进行了load的操作”->2.工作台内容存旧读新，working time存旧迎新
                    FileCommand *commandA = new mdFile(filePath);
                    Invoker invoker;
                    invoker.setFileCommand(commandA);
                    invoker.executeLoadCommand();
                    delete commandA;
                    //3.更新history
                    history.push_back(getTime() + command);
                }
                else{//如果名字被占用，就delete
                    delete temp;
                    cout<<"error:同名workspace已存在！"<<endl;
                }
            }
            else
            {
                cout << "路径" << filePath << "有非法字符或者路径不正确" << endl;
            }
}
void CommandParser::CommandParseSave(string command){
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
                //把save history写入workspace的wsCommands
                WorkSpace *w = findWorkspaceByFileName(currentFileName);
                w->wsCommands.push_back("save");
            }
}
void CommandParser::CommandParseInsert(string command){
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
                //cout << "##Command被重写入history为" << command << endl;
                history.push_back(getTime() + command);
                //contentsCommandHistory.push_back(command);
            }
            else if (tempFlag == -1) // insert到末尾
            {
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(currentFileContents.size(), command);
                delete commandA;
                command = "insert " + to_string(currentFileContents.size()-1) + " " + command;
                //cout << "##Command被重写入history为" << command << endl;
                history.push_back(getTime() + command);
            }
            else
            {
                printf("insert 格式不正确");
            }
}
void CommandParser::CommandParseAppend(string command){
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
void CommandParser::CommandParseDelete(string command){
            string command_ = command.substr(command.find_first_of(" ") + 1);
            deleteCommand *commandA = new deleteCommand();
            Invoker invoker;
            invoker.setDeleteCommand(commandA);
            int temp = 0;
            history.push_back(getTime()+command);
            for (auto c : command_)
            {
                if (c <= '9' && c >= '0')
                {
                    ;
                }
                else
                {
                    invoker.executeDeleteCommand(command_);//delete string
                    temp = 1;
                    break;
                }
            }
            if (temp == 0 && stoi(command_) > 0){//delete number
                invoker.executeDeleteCommand(stoi(command_));
            }  
            delete commandA;
}
void CommandParser::CommandParseUndo(string command){
            history.push_back(getTime() + command);
            if (contentsCommandHistory.size()>=1&&contentsCommandHistory[contentsCommandHistory.size()-1].find("insert ")==0)
            {
                string a = contentsCommandHistory[contentsCommandHistory.size()-1];
                int temp1 = a.find("insert ")+7;
                a = a.substr(temp1);
                a = a.substr(0,a.find(" "));//a是表示第几行
                deleteCommand *commandA = new deleteCommand();
                Invoker invoker;
                invoker.setDeleteCommand(commandA);
                invoker.executeDeleteCommand(stoi(a));//提示：delete自动写了history
                //对history进行操作
                contentsCommandHistory.pop_back();//把delete自动写入history的记录删掉
                contentsCommandHistory.push_back("undo");//undo成功的话插入一个undo
                //把undo history写入workspace的wsCommands
                WorkSpace *w = findWorkspaceByFileName(currentFileName);
                w->wsCommands.pop_back();
                w->wsCommands.push_back("undo");
            }
            else if (contentsCommandHistory.size()>=1&&contentsCommandHistory[contentsCommandHistory.size()-1].find("delete")==0)
            {
                string inner_process = contentsCommandHistory[contentsCommandHistory.size()-1];
                inner_process = inner_process.substr(inner_process.find("delete")+7);
                int number_line = stoi(inner_process.substr(0, inner_process.find_first_of(" ")));//number是代表第几行
                string text = inner_process.substr(inner_process.find_first_of(" ")+1);//text是被删掉的内容
                insertCommand *commandA = new insertCommand;
                Invoker invoker;
                invoker.setInsertCommand(commandA);
                invoker.executeInsertCommand(number_line, text);
                delete commandA;
                //inner_process = "insert "+inner_process;//这里变成undo实际上执行的操作
                contentsCommandHistory.pop_back();//把insert自动写入history的记录删掉
                contentsCommandHistory.push_back("undo");//成功的话插入一个undo
                //把undo history写入workspace的wsCommands
                WorkSpace *w = findWorkspaceByFileName(currentFileName);
                w->wsCommands.pop_back();
                w->wsCommands.push_back("undo");
            }
            else
            {
                cout << "您只能撤销插入和删除操作"<<endl;
            }

}
void CommandParser::CommandParseRedo(string command){
    history.push_back(getTime() + command);
    if(contentsCommandHistory[contentsCommandHistory.size()-1].find("undo")==0){
                if (contentsCommandHistory[contentsCommandHistory.size()-2].find("insert ")==0)
                {
                    string a = contentsCommandHistory[contentsCommandHistory.size() - 2];
                    int pos = a.find_first_of(" ");
                    a = a.substr(pos + 1);//去掉了insert
                    int number_line = stoi(a.substr(0, command.find_first_of(" ")));
                    string text = a.substr(a.find_first_of(" ") + 1);
                    insertCommand *commandA = new insertCommand();
                    Invoker invoker;
                    invoker.setInsertCommand(commandA);
                    invoker.executeInsertCommand(number_line,text);//insert自动写了contents command history

                    contentsCommandHistory.pop_back();//把自动写的insert pop出来
                    contentsCommandHistory.pop_back();//把undo pop出来
                    //把redo history写入workspace的wsCommands
                    WorkSpace *w = findWorkspaceByFileName(currentFileName);
                    w->wsCommands.pop_back();
                    w->wsCommands.pop_back();
                }
                else if (contentsCommandHistory[contentsCommandHistory.size() - 2].find("delete")==0)
                {
                    string inner_process = contentsCommandHistory[contentsCommandHistory.size() - 2];
                    inner_process = inner_process.substr(inner_process.find("delete")+7);
                    int number_line = stoi(inner_process.substr(0, inner_process.find_first_of(" ")));//number是代表第几行
                    string text = inner_process.substr(inner_process.find_first_of(" ")+1);//text是被删掉的内容
                    deleteCommand *commandA = new deleteCommand;
                    Invoker invoker;
                    invoker.setDeleteCommand(commandA);
                    invoker.executeDeleteCommand(number_line);
                    delete commandA;
                    contentsCommandHistory.pop_back();//把自动写入的delete出来
                    contentsCommandHistory.pop_back();//把undo pop出来
                    //把redo history写入workspace的wsCommands
                    WorkSpace *w = findWorkspaceByFileName(currentFileName);
                    w->wsCommands.pop_back();
                    w->wsCommands.pop_back();
                }
            }
            else
            {
                //cout<<"error:there is no undo."<<endl;
            }

}
void CommandParser::CommandParseList_tree(string command){
                    Display *commandA = new Display;
                    Invoker invoker;
                    invoker.setDisplayCommand(commandA);
                    invoker.executeListTreeCommand();
                    history.push_back(getTime() + command);
}
void CommandParser::CommandParseList(string command){
                    Display *commandA = new Display;
                    Invoker invoker;
                    invoker.setDisplayCommand(commandA);
                    invoker.executeListCommand();
                    history.push_back(getTime() + command);
}
void CommandParser::CommandParseDir_tree(string command){
                    string dir;
                    if (command.back() == '\n') {
                        command = command.substr(0, command.length() - 1);
                    }
                    if (command.find(" ")>0&&command.substr(command.find(" ")+1)!="")//有指定目录
                    {
                        dir = command.substr(command.find(" ")+1);
                    }
                    else
                    {
                        dir = "root";
                    }
                    Display *commandA = new Display;
                    Invoker invoker;
                    invoker.setDisplayCommand(commandA);
                    invoker.executeListDirTreeCommand(dir);
                    history.push_back(getTime() + command);
}
void CommandParser::CommandParseHistory(string command){
                    int number;
                    if (command.back() == '\n') {
                        command = command.substr(0, command.length() - 1);
                    }
                    if (command.find(" ")>0&&command.substr(command.find(" ")+1)!="")//有指定行数
                    {
                        string a = command.substr(command.find(" ")+1);
                        number = stoi(command.substr(command.find(" ")+1));
                    }
                    else number = -1;//全输出
                    for(int i = 0;i<history.size()&&i<number;i++){
                        cout<<history[history.size()-1-i]<<endl;
                    }

}
void CommandParser::CommandParseList_workspace(string command){//8
    history.push_back(getTime() + command);
    List_workspaceCommand *commandA = new List_workspaceCommand;
    Invoker invoker;
    invoker.setList_workspaceCommand(commandA);
    invoker.executeCommand();
}
void CommandParser::CommandParseOpen(string command){//13
    history.push_back(getTime() + command);
    string openWorkspaceName = "";
    if (!history.empty()) {
        string& latestCommand = history.back(); // 获取最新的命令
        string openCommandPrefix = "open ";
        size_t prefixPos = latestCommand.find(openCommandPrefix);
        if (prefixPos != string::npos) {
            openWorkspaceName = latestCommand.substr(prefixPos + openCommandPrefix.length());
        }
    }
    if(openWorkspaceName!=""){//解析出了命令行想打开的workspace name
        OpenCommand *commandA = new OpenCommand;
        Invoker invoker;
        invoker.setOpenCommand(commandA);
        invoker.executeCommand();
    }
    else{
        cout<<"open命令解析错误"<<endl;
    }
    
}
void CommandParser::CommandParseClose(string command){//14
    history.push_back(getTime() + command);
    CloseCommand *commandA = new CloseCommand;
    Invoker invoker;
    invoker.setCloseCommand(commandA);
    invoker.executeCommand();
}
void CommandParser::CommandParseExit(string command){//15
    history.push_back(getTime() + command);
    ExitCommand *commandA = new ExitCommand;
    Invoker invoker;
    invoker.setExitCommand(commandA);
    invoker.executeCommand();
}

void CommandParser::CommandParseLs(string command){//16
    history.push_back(getTime() + command);
    LsCommand *commandA = new LsCommand;
    Invoker invoker;
    invoker.setLsCommand(commandA);
    invoker.executeCommand();
}
