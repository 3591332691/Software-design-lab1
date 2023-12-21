#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <time.h>
#include <string>
#include "../File/WorkSpace.h"
using namespace std;

string getTime();
int checkWhichCommand(std::string command);
int find_the_level(std::string str);
void showCurrentFileContents();
void showContentsCommandHistory();
bool checkWorkSpaceNameOccupied(string workspace_name);
WorkSpace* findWorkspaceByName(const std::string& workspaceName);
WorkSpace* findWorkspaceByFileName(const std::string& fileName);
void pushWorkspaceIntoWorkingTime(WorkSpace* a);
void printWorkingTime();
int checkWorkSpaceStatus(WorkSpace *a);

struct Working_directoryTreeNode {
    string NodeName;
    vector<struct Working_directoryTreeNode*> children;
    int level;
    struct Working_directoryTreeNode* parent;
};

Working_directoryTreeNode* buildDirectoryTree(const string& path, Working_directoryTreeNode* parent = nullptr);
void displayDirectoryTree(Working_directoryTreeNode* node, bool isLastChild = false, std::string indent = "");


void clearFolder(const std::string& folderPath);
#endif