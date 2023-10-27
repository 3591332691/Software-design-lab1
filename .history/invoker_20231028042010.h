#ifndef INVOKER_H
#define INVOKER_H
#include <string.h>
#include "FileCommand.h"
#include "ContentsCommand.h"
#include<iostream>
class Invoker {
private:
    FileCommand* fileCommand;
    insertCommand* InsertCommand;
public:
    void setFileCommand(FileCommand* cmd) {
        fileCommand = cmd;
    }

    void executeLoadCommand() {
        fileCommand->load();
    }
    void executeSaveCommand() {
        fileCommand->save();
    }

    void setInsertCommand(insertCommand* cmda){
        InsertCommand = cmda;
    }
    void executeInsertCommand(int lineNumber, std::string str) {
        InsertCommand->insert(int lineNumber, std::string str);
    }
};
#endif