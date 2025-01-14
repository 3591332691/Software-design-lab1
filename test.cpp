#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include "src\\FileCommand\\FileCommand.h"
#include "src\\invoker.h"
#include "src\\ContentsCommand\\ContentsCommand.h"
#include "src\\tool\\tool.h"
#include "src\\CommandParser\\CommandParser.h"
#include "src\\File\\WorkSpace.h"
#include "src\\constants.h"
#include "test.h"
using namespace std;
vector<string> commands; // for test
string currentFileName = "";
vector<string> currentFileContents;
vector<string> history;
vector<string> contentsCommandHistory;//for undo&redo only have insert&delete
vector<WorkSpace*> workspaces;
vector<string> workingTime;
int currentWorkSpaceId = 0;
int testCommand(vector<string> commands)
{
    for (auto command : commands)
    {   
        switch (checkWhichCommand(command))
        {
        case 0://load
        {
            CommandParser a;
            a.CommandParseLoad(command);
            break;
        }
        case 1://save
        {
            CommandParser a;
            a.CommandParseSave(command);
            break;
        }
        case 2://insert
        {
            CommandParser a;
            a.CommandParseInsert(command);
            break;
        }
        case 3://append-
        {
            CommandParser a;
            a.CommandParseAppend(command);
            break;
        }
        case 4://delete
        {
            CommandParser a;
            a.CommandParseDelete(command);
            break;
        }
        case 5://undo
        {
            CommandParser a;
            a.CommandParseUndo(command);
            break;
        }
        case 6://redo
        {
            CommandParser a;
            a.CommandParseRedo(command);
            break;
        }
        case 7://list-tree
        {
            CommandParser a;
            a.CommandParseList_tree(command);
            break;
        }
        case 8://list-workspace
        {
            CommandParser a;
            a.CommandParseList_workspace(command);//showCurrentFileContents();
            break;
        }
        case 9://dir-tree
        {
            CommandParser a;
            a.CommandParseDir_tree(command);
            break;
        }
        case 10://history
        {
            CommandParser a;
            a.CommandParseHistory(command);
            break;
        }
        case 11://stats
        {
            CommandParser a;
            a.CommandParseExit(command);
            break;
        }
        case 12://list
        {   
            CommandParser a;
            a.CommandParseList(command);
            break;
        }
        case 13://open
        {   
            CommandParser a;
            a.CommandParseOpen(command);
            break;
        }
        case 14://close
        {   
            CommandParser a;
            a.CommandParseClose(command);
            break;
        }
        case 15://exit
        {
            CommandParser a;
            a.CommandParseExit(command);
            break;
        }
        case 16://ls
        {
            CommandParser a;
            a.CommandParseLs(command);
            break;
        }
        default:
        {
            cout << "未识别出正确命令" << endl;
            break;
        }
        }
        //showCurrentFileContents();//TODO:写、检查完之后要删掉。
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
    testCommand(commands);
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
    testCommand(commands);
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
    testCommand(commands);
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
    testCommand(commands);
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
    testCommand(commands);
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
    str = "delete to be the head";
    commands.push_back(str);
    str = "undo \n";
    //commands.push_back(str);
    //str = "redo \n";
    commands.push_back(str);
    str = "save \n";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
int testCommandList()
{
    commands.clear();
    string str;
    string filename1 = "../testplace/txt1.md";
    str = "load " + filename1 + "\n";
    commands.push_back(str);
    str = "load test1.md";
    commands.push_back(str);
    str = "insert ## 程序设计";
    commands.push_back(str);
    str = "append-head # 我的资源";
    commands.push_back(str);
    str = "append-tail ### 软件设计";
    commands.push_back(str);
    str = "append-tail 1. 观察者模式";
    commands.push_back(str);
    str = "append-tail ## ⼯具箱";
    commands.push_back(str);
    str = "append-tail ### Adobe";
    commands.push_back(str);
    str = "dir-tree \n";
    commands.push_back(str);
    str = "dir-tree ⼯具箱\n";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
int freeTest()
{
    string input;
    while (getline(cin, input) && input != "eof")
    {
        //TODO:输入的是中文的时候无法显示
        //cout<<" "<<input<<endl;
        commands.clear();
        commands.push_back(input);
        testCommand(commands);
        if(input =="exit")break;
    }
    return 0;
}
int initial()
{
    commands.clear();
    currentFileName = "";
    currentFileContents.clear();
    history.clear();
    contentsCommandHistory.clear();

    SessionMemento a;
    workspaces.clear();
    a.getWorkspaces();//读取原来的backup 里的workspaces
    //
    string sessionStart = "session start at ";
    sessionStart += getTime();
    ofstream file1(historylogPath, ios::app);
    if (!file1.is_open()) {
        // 文件打开失败，处理错误
        cout<<"Error:打开historyLog失败"<<endl;
    }
    else{
        file1 << sessionStart << endl;
        // 关闭文件
        file1.close();
    }
    ofstream file2(worktimeLogPath, ios::app);
    if (!file2.is_open()) {
        // 文件打开失败，处理错误
        cout<<"Error:打开historyLog失败"<<endl;
    }
    else{
        file2 << sessionStart << endl;
        // 关闭文件
        file2.close();
    }
    return 0;
}

int test1(){
    commands.clear();
    string str;
    str = "load test1.md" ;
    commands.push_back(str);
    str = "insert ## 程序设计";
    commands.push_back(str);
    str = "append-head # 我的资源";
    commands.push_back(str);
    str = "append-tail ### 软件设计";
    commands.push_back(str);
    str = "append-tail #### 设计模式";
    commands.push_back(str);
    str = "append-tail 1. 观察者模式";
    commands.push_back(str);
    str = "append-tail 3. 单例模式";
    commands.push_back(str);
    str = "insert 6 2. 策略模式";
    commands.push_back(str);
    str = "delete 单例模式";
    commands.push_back(str);
    str = "append-tail 3. 组合模式";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "append-tail ## ⼯具箱";
    commands.push_back(str);
    str = "append-tail ### Adobe";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "save";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
int test2(){
    commands.clear();
    string str;
    str = "load test2.md" ;
    commands.push_back(str);
    str = "append-head # 旅⾏清单";
    commands.push_back(str);
    str = "append-tail ## 亚洲";
    commands.push_back(str);
    str = "append-tail 1. 中国";
    commands.push_back(str);
    str = "append-tail 2. ⽇本";
    commands.push_back(str);
    str = "delete 亚洲";
    commands.push_back(str);
    str = "undo";
    commands.push_back(str);
    str = "redo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "save";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
int test3(){
    commands.clear();
    string str;
    str = "load test3.md" ;
    commands.push_back(str);
    str = "append-head # 书籍推荐";
    commands.push_back(str);
    str = "append-tail * 《深入理解计算机系统》";
    commands.push_back(str);
    str = "undo";
    commands.push_back(str);
    str = "append-tail ## 编程";
    commands.push_back(str);
    str = "append-tail * 《设计模式的艺术》";
    commands.push_back(str);
    str = "redo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "append-tail * 《云原⽣：运⽤容器、函数计算和数据构建下⼀代应⽤》";
    commands.push_back(str);
    str = "append-tail * 《深入理解Java虚拟机》";
    commands.push_back(str);
    str = "undo";
    commands.push_back(str);
    str = "redo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "save";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
int test4(){
    commands.clear();
    string str;
    str = "load test4.md" ;
    commands.push_back(str);
    str = "append-head # 旅⾏清单";
    commands.push_back(str);
    str = "append-tail ## 亚洲";
    commands.push_back(str);
    str = "save";
    commands.push_back(str);
    str = "append-tail 1. 中国";
    commands.push_back(str);
    str = "append-tail 2. ⽇本";
    commands.push_back(str);
    str = "append-tail ## 欧洲";
    commands.push_back(str);
    str = "load test3.md";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "load test4.md";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
int test5(){
    commands.clear();
    string str;
    str = "load test5.md" ;
    commands.push_back(str);
    str = "append-head # 旅⾏清单";
    commands.push_back(str);
    str = "append-tail ## 欧洲";
    commands.push_back(str);
    str = "insert 2 ## 亚洲";
    commands.push_back(str);
    str = "insert 3 1. 中国";
    commands.push_back(str);
    str = "insert 4 2. ⽇本";
    commands.push_back(str);
    str = "save";
    commands.push_back(str);
    str = "undo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "delete 亚洲";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "history 2";
    commands.push_back(str);
    str = "undo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "redo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "redo";
    commands.push_back(str);
    str = "list-tree";
    commands.push_back(str);
    str = "save";
    commands.push_back(str);
    testCommand(commands);
    return 0;
}
//int main(int argc, char** argv)
//{
    // testCommandLoad();
    // testCommandSave();
    // testCommandInsert();
    // testCommandAppend();
    // testCommandDelete();
    //initial();
    //testCommandList();
    //testCommandUndo();
    

    //start session的时候写入两个log开头
    /*
    
    
    freeTest();
    */
   //return 0;
//}

