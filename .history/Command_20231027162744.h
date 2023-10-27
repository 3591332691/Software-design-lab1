#ifndef COMMAND_H
 #define  COMMAND_H

public classFileCommand{
    public: virtual void open() = 0;
            virtual void save() = 0;
};
public interface File extends FileCommand{
    void getFileName();
};
public class mdFile implements File{
    string filename;
    void open();
    void save();

};
public class loadSaveCommand implements FileCommand{

}

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