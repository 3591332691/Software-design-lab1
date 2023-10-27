#include <iostream>
using namespace std;
#ifndef Command_H
 #define  CIRCLE_H

public interface FileCommand{
    void open();
    void save();
};
public interface File extends FileCommand{
    void getFileName();
};
public class mdFile implements File{

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