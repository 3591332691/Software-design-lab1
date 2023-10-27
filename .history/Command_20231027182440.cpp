#include <iostream>
#include <fstream>
#include "Command.h"
using namespace std;


void mdFile::load() {
    ifstream file(filename);
    if (file.is_open()) {
        string line;

        while (std::getline(file, line)) {
            contents.push_back(line);
        }
        file.close();
    } else {
        ofstream create_file (filename);
        create_file.close();
    }
}
void mdFile::save(){
    
}