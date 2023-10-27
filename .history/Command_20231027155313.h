#include <iostream>
using namespace std;


public interface FileCommand{
    void open();
    void save();
};
loadSaveCommand implement
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};