#include <iostream>
#include <fstream>
#include"Command.h"
using namespace std;


int mdFile::create(string filename){
    ofstream file;
    file.open(filename,ios::out);
}