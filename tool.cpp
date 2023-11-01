#include <vector>
#include<iostream>
#include <time.h>
#include<string>
#include "tool.h"
using namespace std;


vector<string> commandsSummary = {"load","save","insert","append-","delete","undo","redo","list",""};
/// @brief 
/// @return 
string getTime(){
    time_t t = time(0); 
    char tmp[32];
    strftime(tmp, sizeof(tmp), "%Y%m%d %H:%M:%S ",localtime(&t)); 
    return string(tmp);
}
int checkWhichCommand(string a){
    for(int i = 0;i<commandsSummary.size();i++){
        if(a.find(commandsSummary[i]))return i;
    }
    return -1;
}