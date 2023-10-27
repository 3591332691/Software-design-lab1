#include <iostream>
#include <fstream>
#include"Command.h"
using namespace std;


void mdFile::getFilename(string str){
    ofstream file;
    file.open(filename,ios::out);
}