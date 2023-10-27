#ifndef COMMAND_H
#define  COMMAND_H

public class FileCommand{
    public: 
    virtual void open() = 0;
    virtual void save() = 0;
};

public class mdFile extends FileCommand{
    public:
    string filename;
    void open();
    void save();
    void getFilename(string str);
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