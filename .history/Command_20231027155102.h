#include <iostream>
using namespace std;


public interface FileCommand{
    void open();
    
};
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};