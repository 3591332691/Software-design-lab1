#include <iostream>
#include <fstream>
#include "Command.h"
using namespace std;


void mdFile::load(){
    ofstream file("path/to/example.md", std::ios::app);
}
