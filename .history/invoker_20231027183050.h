#ifndef IN_H
#define  COMMAND_H
#include <string.h>
#include "Command.h"
class Invoker {
private:
    FileCommand* fileCommand;

public:
    void setFileCommand(FileCommand* cmd) {
        fileCommand = cmd;
    }

    void executeLoadCommand() {
        fileCommand->load();
    }
};