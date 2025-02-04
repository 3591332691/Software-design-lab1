#ifndef FILECOMMAND_H
#define  FILECOMMAND_H
#include <string>
#include <vector>
class FileCommand{
    public: 
    virtual void load() = 0;
    virtual void save() = 0;
};

class mdFile : public FileCommand {
    public:
    std::string filename;
    std::vector<std::string> contents;
    void save() override;
    void load() override;
    mdFile(std::string str){
        filename = str;
    }
};

#endif