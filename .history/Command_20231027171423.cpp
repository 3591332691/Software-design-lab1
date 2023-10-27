#include <iostream>
#include <fstream>
#include "Command.h"
using namespace std;


void mdFile::load(){
    ofstream file(filename, app);
}
