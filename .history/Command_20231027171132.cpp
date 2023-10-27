#include <iostream>
#include <fstream>
#include "Command.h"
using namespace std;


void mdFile::open(){
    if(filename!="")
    {
        create
    };
}
void mdFile::create(){
    ofstream ofs;
    ofstream file("path/to/example.md", std::ios::app);
}