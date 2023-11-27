#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>

class CommandParser{

    public:
        void CommandParseLoad(string commandLine);
        void CommandParseSave(string commandLine);
        void CommandParseInsert(string commandLine);
        void CommandParseAppend(string commandLine);
        void CommandParseDelete(string commandLine);
        void CommandParseUndo(string commandLine);
        void CommandParseRedo(string commandLine);
        void CommandParseList_tree(string commandLine);
        void CommandParseList(string commandLine);
        void CommandParseDir_tree(string commandLine);
        void CommandParseHistory(string commandLine);
};
#endif