#include <iostream>
using namespace std;


public interface FileCommand{
    
};
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};