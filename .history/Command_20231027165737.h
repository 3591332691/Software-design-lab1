#ifndef COMMAND_H
#define  COMMAND_H
#include <string>

class FileCommand{
    public: 
    virtual void open() = 0;
    virtual void save() = 0;
};

class mdFile : public FileCommand {
    public:
    string filename;
    void open();
    void save();
    mdFile(string str){
        filename = str;
    }
};

/*
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};
*/
#endif