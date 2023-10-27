#include <iostream>
#include <fstream>
#include"Command.h"
using namespace std;


int mdFile::getFilename(string filename){
    ofstream file;
    file.open(filename,ios::out);
}