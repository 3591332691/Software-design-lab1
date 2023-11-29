#ifndef SESSION_H
#define SESSION_H
#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <ctype.h>
#include "FileCommand\\FileCommand.h"
#include "invoker.h"
#include "ContentsCommand\\ContentsCommand.h"
#include "tool\\tool.h"
#include "CommandParser\\CommandParser.h"
using namespace std;


class Session{
    public:
    vector<string> commands; // for test
    string currentFileName;
    vector<string> currentFileContents;
    vector<string> history;
    vector<string> contentsCommandHistory;//for undo&redo only have insert&delete

    void runSession();
    Session();
    ~Session();
};
#endif