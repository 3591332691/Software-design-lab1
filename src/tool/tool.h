#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

string getTime();
int checkWhichCommand(std::string command);
int find_the_level(std::string str);
void showCurrentFileContents();
void showContentsCommandHistory();
bool checkWorkSpaceNameOccupied(string workspace_name);
#endif