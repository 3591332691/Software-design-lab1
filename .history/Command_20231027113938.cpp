#include <iostream>
using namespace std;

class CommandFile{
    int create(string filename);
    int load();
    int save();
    int list();
};
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};