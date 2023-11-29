#ifndef INVOKER_H
#define INVOKER_H
#include <string.h>
#include "FileCommand\\FileCommand.h"
#include "ContentsCommand\\ContentsCommand.h"
#include "ShowCommand\\ShowCommand.h"
#include "SessionCommand\\SessionCommand.h"
#include<iostream>
class Invoker {
private:
    FileCommand* fileCommand;
    insertCommand* InsertCommand;
    deleteCommand* DeleteCommand;
    Display* display;
    Command* origin_command;
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
        InsertCommand->insert(lineNumber,str);
    }
    void setDeleteCommand(deleteCommand* cmd){
        DeleteCommand = cmd;
    }
    void executeDeleteCommand(int lineNumber){
        DeleteCommand->delete_(lineNumber);
    }
    void executeDeleteCommand(std::string str){
        DeleteCommand->delete_(str);
    }
    void setDisplayCommand(Display* cmd){
        display = cmd;
    }
    void executeListCommand(){
        display->display();
    }
    void executeListTreeCommand(){
        display->display_tree();
    }
    void executeListDirTreeCommand(std::string str){
        display->display_dir_tree( str);
    }
    //new try:
    void setExitCommand(ExitCommand* cmd){
        origin_command = cmd;
    }
    void setList_workspaceCommand(List_workspaceCommand* cmd){
        origin_command = cmd;
    }
    void setCloseCommand(CloseCommand* cmd){
        origin_command = cmd;
    }
    void executeCommand(){
        origin_command->execute();
    }

};
#endif