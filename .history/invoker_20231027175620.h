class Invoker {
private:
    Command* command;

public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void executeCommand() {
        std::cout << "Invoker executes command..." << std::endl;
        command->execute();
    }
};