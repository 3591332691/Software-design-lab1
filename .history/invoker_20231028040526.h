#ifndef INVOKER_H
#define INVOKER_H
#include <string.h>
#include "FileCommand.h"
#include "ContentsCommand.h"
class Invoker {
private:
    FileCommand* fileCommand;
    insertCommand* insertCommand;
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

    void setInsertCommand(InsertCommand* cmd){
        insertCommand = cmd;
    }
    void executeUpdateCommand() {}
};
#endif