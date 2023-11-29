#ifndef SESSIONCOMMAND_H
#define SESSIONCOMMAND_H
#include "Command.h"
#include <iostream>
using namespace std;

class List_workspaceCommand : public Command{
public:
    void execute() override;
};

class CloseCommand : public Command{
public:
    void execute() override;
};

class OpenCommand : public Command{
public:
    void execute() override;
};

class ExitCommand : public Command{
public:
    void execute() override;
};
#endif