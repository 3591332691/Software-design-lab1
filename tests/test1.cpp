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
string expectedOutput1 = "└──书籍推荐\n"
                        "   └──编程\n"
                        "      ├──《设计模式的艺术》\n"
                        "      ├──《云原生：运用容器、函数计算和数据构建下一代应用》\n"
                        "      └──《深入理解Java虚拟机》\n"
                        ;
TEST(MyTests, Test1) {

    string expectedOutput2 = "  test1 *\n"
                             "->test2 *\n"
                             ;
    string expectedOutput3 = "  test1 *\n"
                             "->test2\n"
                             ;
    string expectedOutput4 = "->test1 *\n"
                             "  test2\n"
                             ;
    // 编写测试代码和断言
    testing::internal::CaptureStdout();
    initial();
    string str;
    str = "load test1.md\n";
    commands.push_back(str);
    str = "append-head # 旅行清单\n";
    commands.push_back(str);
    str = "append-tail ## 亚洲\n";
    commands.push_back(str);
    str = "append-tail 1. 中国\n";
    commands.push_back(str);
    str = "append-tail 2. 日本\n";
    commands.push_back(str);
    str = "load test2.md\n";
    commands.push_back(str);
    str = "append-head # 书籍推荐\n";
    commands.push_back(str);
    str = "append-tail ## 编程\n";
    commands.push_back(str);
    str = "append-tail * 《设计模式的艺术》\n";
    commands.push_back(str);
    str = "append-tail * 《云原生：运用容器、函数计算和数据构建下一代应用》\n";
    commands.push_back(str);
    str = "append-tail * 《深入理解Java虚拟机》\n";
    commands.push_back(str);
    //showCurrentFileContents();
    str = "list-tree\n";
    commands.push_back(str);
    testCommand(commands);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput1, output);


    //part2
    testing::internal::CaptureStdout();
    commands.clear();
    str = "list-workspace\n";
    commands.push_back(str);
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput2, output);


    //part3
    testing::internal::CaptureStdout();
    commands.clear();
    str = "save\n";
    commands.push_back(str);
    str = "list-workspace\n";
    commands.push_back(str);
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput3, output);
    //part4
    testing::internal::CaptureStdout();
    commands.clear();
    str = "open test1\n";
    commands.push_back(str);
    str = "list-workspace\n";
    commands.push_back(str);
    testCommand(commands);
    output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(expectedOutput4, output);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

