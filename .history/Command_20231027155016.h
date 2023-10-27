#include <iostream>
using namespace std;

class CommandFile{
    int create(string filename);//load--if there is not the file,create one
    int load(string filename);//load--if the file exists, switch to it
    int save(string filename);//save--
};
public interface FileCommand{

};
class CommandContent{
    int add();
    int erase();
};
class CommandSummary{
    int draw();
};