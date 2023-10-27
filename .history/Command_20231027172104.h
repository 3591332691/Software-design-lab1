#ifndef COMMAND_H
#define  COMMAND_H
#include <string>
#include <vector>

class FileCommand{
    public: 
    virtual void open() = 0;
    virtual void save() = 0;
};

class mdFile : public FileCommand {
    public:
    std::string filename;
    std::vector<std::string> contents;
    void save();
    void load();
    mdFile(std::string str){
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