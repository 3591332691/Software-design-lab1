
#ifndef WORKSPACE_H
#define  WORKSPACE_H
#include <string>
#include <vector>
#include "File.h"
using namespace std;

class WorkSpace : public File {
    private:
    string workspace_name;
    public:
    string get_workspace_name() const { return workspace_name; }
    //暂时用来存储对这个workspace(file)进行过的操作，用来观察状态是未修改/已修改未保存/已修改已保存
    vector<string> wsCommands;
    //构造函数
    WorkSpace(string filepath);
    //构造函数的帮助函数
    void set_workspace_name(string a);
    //用来保存工作区的内容
    vector<string> workspace_content;
    string getWorkspaceContent();
    void setWorkingSpaceContent(vector<string> a);
    //用于删除自身
    void kill();
};

#endif