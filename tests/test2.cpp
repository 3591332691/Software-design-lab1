#include <gtest/gtest.h> // 包含测试框架的头文件
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include "../FileCommand/FileCommand.h"
#include "../invoker.h"
#include "../ContentsCommand/ContentsCommand.h"
#include "../tool/tool.h"
#include "../CommandParser/CommandParser.h"
#include "../File/WorkSpace.h"
#include "../constants.h"
#include "../test.h"
using namespace std;
extern vector<string> commands; // for test
extern string currentFileName;
extern vector<string> currentFileContents;
extern vector<string> history;
extern vector<string> contentsCommandHistory;//for undo&redo only have insert&delete
extern vector<WorkSpace*> workspaces;
extern vector<string> workingTime;
string expectedOutput21 = "Do you want to save the current workspace [Y\\N] ?";
string expectedOutput22 = "->test3 *\n";
string expectedOutput23 = "Do you want to save the unsaved workspace [Y\\N] ?";

TEST(MyTests, Test2) {
    //part1
    testing::internal::CaptureStdout();
    initial();
    string str;
    str = "load test3.md\n";
    commands.push_back(str);
    str = "insert ## 程序设计\n";
    commands.push_back(str);
    str = "append-head # 我的资源\n";
    commands.push_back(str);
    str = "append-tail ### 软件设计\n";
    commands.push_back(str);
    str = "load test4.md\n";
    commands.push_back(str);
    str = "append-head # 大学合集\n";
    commands.push_back(str);
    str = "append-tail 1. 复旦大学\n";
    commands.push_back(str);
    str = "append-tail 2. 上海交通大学\n";
    commands.push_back(str);
    str = "close\n";
    commands.push_back(str);
    testCommand(commands);
    
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput21, output);
    //part2

    testing::internal::CaptureStdout();
    commands.clear();
    str = "open test3\n";
    commands.push_back(str);
    str = "list-workspace\n";
    commands.push_back(str);
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput22, output);
    //part3

    testing::internal::CaptureStdout();
    commands.clear();
    str = "exit";
    commands.push_back(str);
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput23, output);
}

TEST(MyTests, Test3) {
    string expectedOutput31 = 
                              "├── test5.md *\n"
                              "└── data\n"
                              "    └── data1.md\n";
    testing::internal::CaptureStdout();
    initial();
    string str;
    str = "load ../tests/002/test5.md\n";
    commands.push_back(str);
    str = "append-head # 书籍推荐\n";
    commands.push_back(str);
    str = "append-tail * 《深入理解计算机系统》\n";
    commands.push_back(str);
    str = "ls\n";
    commands.push_back(str);
    testCommand(commands);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput31, output);
}

TEST(MyTests, Test4) {
    string expectedOutput41 = 
                              "└── 大学合集\n"
                              "   └── 1. 复旦大学\n";
    string expectedOutput42 = 
    "  test6\n"
    "->test7\n";
    string expectedOutput43 = 
    "└── 大学合集\n"
    "   ├── 1. 复旦大学\n"
    "   └── 2. 上海交通大学\n";
    testing::internal::CaptureStdout();
    initial();
    string str;
    str = "load test6.md\n";
    commands.push_back(str);
    str = "insert ## 程序设计\n";
    commands.push_back(str);
    str = "append-head # 我的资源\n";
    commands.push_back(str);
    str = "append-tail ### 软件设计\n";
    commands.push_back(str);
    str = "save\n";
    commands.push_back(str);
    str = "load test7.md\n";
    commands.push_back(str);
    str = "append-head # 大学合集\n";
    commands.push_back(str);
    str = "append-tail 1. 复旦大学\n";
    commands.push_back(str);
    str = "append-tail 2. 上海交通大学\n";
    commands.push_back(str);
    str = "undo\n";
    commands.push_back(str);
    str = "list-tree\n";
    commands.push_back(str);
    testCommand(commands);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput41, output);

    //part2
    testing::internal::CaptureStdout();
    commands.clear();
    str = "save\n";
    commands.push_back(str);
    str = "exit\n";
    commands.push_back(str);
    testCommand(commands);
    initial();//重新启动
    str = "list-workspace\n";
    commands.push_back(str);
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput42, output);
    //part3
    testing::internal::CaptureStdout();
    commands.clear();
    str = "redo\n";
    commands.push_back(str);
    str = "list-tree\n";
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput43, output);
}
