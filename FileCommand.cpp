#include <iostream>
#include <fstream>
#include "FileCommand.h"
using namespace std;

extern vector <string> currentFileContents;
void mdFile::load() {
    ifstream file(filename,ios::in);
    if (file.is_open()) 
    {
        string line;

        while (std::getline(file, line)) {
            contents.push_back(line);
        }
        file.close();
        currentFileContents = contents;//在这里把内容存在currentFileContents里
        contents.clear();
    } 
    else 
    {
        ofstream create_file (filename);
        create_file.close();
        currentFileContents.clear();
    }
}
void mdFile::save(){
    ofstream file(filename,ios::trunc);
    if (file.is_open()) 
    {
        for(auto content : currentFileContents)
        {
             file << content << endl;
        }
    }
    else
    {
        printf("save failed --file not open\n");
    }

}