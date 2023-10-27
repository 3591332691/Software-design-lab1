#ifndef COMMAND_H
 #define  COMMAND_H

public FileCommand{
    void open();
    public: virtual void draw() = 0;
    void save();
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