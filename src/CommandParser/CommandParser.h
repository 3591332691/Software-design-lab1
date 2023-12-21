#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include <string>

class CommandParser{

    public:
        void CommandParseLoad(string commandLine);//0
        void CommandParseSave(string commandLine);
        void CommandParseInsert(string commandLine);
        void CommandParseAppend(string commandLine);
        void CommandParseDelete(string commandLine);
        void CommandParseUndo(string commandLine);
        void CommandParseRedo(string commandLine);
        void CommandParseList_tree(string commandLine);
        void CommandParseList(string commandLine);//12
        void CommandParseDir_tree(string commandLine);
        void CommandParseHistory(string commandLine);//10
        void CommandParseStats(string commandLine);//11
        void CommandParseList_workspace(string commandLine);//8
        void CommandParseOpen(string commandLine);//13
        void CommandParseClose(string commandLine);//14
        void CommandParseExit(string commandLine);//15
        void CommandParseLs(string commandLine);//16
};
#endif