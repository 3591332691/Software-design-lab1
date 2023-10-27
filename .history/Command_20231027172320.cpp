#include <iostream>
#include <fstream>
#include "Command.h"
using namespace std;


void mdFile::load() {
    //ifstream file(filename);
    if (ifstream file(filename)&&file.is_open()) {
        string line;

        while (std::getline(file, line)) {
            contents.push_back(line);
        }

        file.close();
    } else {
        std::cerr << "Failed to open file." << std::endl;
    }
}
void mdFile::save(){

}