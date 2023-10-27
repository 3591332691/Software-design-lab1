#include <iostream>
#include <fstream>
#include
using namespace std;


int CommandFile::create(string filename){
    ofstream file;
    file.open(filename,ios::out);
}