#ifndef COMMAND_H
 #define  COMMAND_H

public interface FileCommand{
    void open();
    void save();
};
public interface File extends FileCommand{
    void getFileName();
};
public class mdFile implements File{
    str
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