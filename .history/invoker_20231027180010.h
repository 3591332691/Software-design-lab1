
#include <string.h>
#include "Command.h"
class Invoker {
private:
    FileCommand* fileCommand;

public:
    void setFileCommand(FileCommand* cmd) {
        fileCommandcommand = cmd;
    }

    void executeCommand() {
        std::cout << "Invoker executes command..." << std::endl;
        command->execute();
    }
};