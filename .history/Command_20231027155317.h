#include <iostream>
using namespace std;


public interface FileCommand{
    void open();
    void save();
};
loadSaveCommand implements FileCommand
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};