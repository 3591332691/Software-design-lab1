#include <iostream>
#include <fstream>
#include "FileCommand.h"
using namespace std;
extern string currentFileName;
extern vector <string> currentFileContents;
void mdFile::load() {
    ifstream file(filename,ios::in);
    if (file.is_open()) 
    {
        currentFileContents.clear();
        string line;
        while (std::getline(file, line)) {
            currentFileContents.push_back(line);
        }
        file.close();

        //currentFileContents = contents;//在这里把内容存在currentFileContents里
        //contents.clear();
    } 
    else 
    {
        ofstream create_file (filename);
        create_file.close();
        currentFileContents.clear();
    }
}
void mdFile::save(){
    ofstream file(currentFileName,ios::trunc);
    if (file.is_open()) 
    {
        for(auto content : currentFileContents)
        {
             file << content << endl;
        }
        cout<<"save "<<currentFileName<<" done"<<endl;
    }
    else
    {
        printf("save failed --file not open\n");
    }

}