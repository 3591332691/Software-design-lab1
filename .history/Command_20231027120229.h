#include <iostream>
using namespace std;

class CommandFile{
    int create(string filename);//load--if there is not the file ,create one
    int load(string filename);
    int save(string filename);
    int list(string filename);
};
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};