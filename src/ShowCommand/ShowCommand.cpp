#include <vector>
#include<iostream>
#include<string>
#include "ShowCommand.h"
using namespace std;
extern vector <string> currentFileContents;

void generateTree(struct TreeNode* preNode, int& index, int level) {                                           
    struct TreeNode* currentNode= new TreeNode();//创造当下的node
    int currentLevel;
    while (index < currentFileContents.size()) {
        
        string line = currentFileContents[index];//取到第index+1行
        if (line.empty()) {
            index++;
            continue;  // 跳过空行
        }

        currentNode->title = line.substr(line.find(" ")+1);//写入title
        if(line.find_first_of('#')==string::npos)//表示是正文
        {
            currentLevel = 100;
            currentNode->title = line;
        }
        else
        {
            currentLevel = line.find_first_not_of('#');//代表是第几级标题
        }

        currentNode->level = currentLevel;//写入level
        if (currentLevel == level) 
        {//同级
            preNode->parent->children.push_back(currentNode); // 前一项的父节点多一个孩子
            currentNode->parent = preNode->parent;//当前项的父节点设置为前一项的父节点
            index++;
            generateTree(currentNode,index,currentLevel);
        } 
        else if (currentLevel > level) 
        {//下一极，current是上一个的子项
            preNode->children.push_back(currentNode);
            currentNode->parent = preNode;
            index++;
            generateTree(currentNode,index,currentLevel);
        } 
        else 
        {//current是上一个的叔叔或者爷爷
            struct TreeNode* findtheParent = preNode;
            while(findtheParent->parent!=nullptr)
            {
                
                if(findtheParent->level >= currentLevel&&findtheParent->parent->level<currentLevel)
                {
                    findtheParent->parent->children.push_back(currentNode);
                    currentNode->parent = findtheParent->parent;
                    break;
                }
                findtheParent= findtheParent->parent;
            }
            index++;
            generateTree(currentNode,index,currentLevel);
        }
    }
}


void printNode(struct TreeNode* node, bool isLastChild = false, string prefix = "") {
    if(node->title!="root"){
        cout << prefix;
        if (isLastChild) {
            cout << "└── ";
            prefix += "   ";
        } else {
            cout << "├── ";
            prefix += "│  ";
        }
        cout << node->title;
    }
    int numChildren = node->children.size();
    for (int i = 0; i < numChildren; i++) {
        struct TreeNode* child = node->children[i];
        if (child->title==node->title) 
        {
            continue;
        }
        bool isLast = (i == numChildren - 1);
        printNode(child, isLast, prefix);
    }
}

void printTreeStructure(struct TreeNode* node) {
    printNode(node, true, "");
}

void Display::display(){
    for(auto line:currentFileContents){
        cout<<line<<endl;
    }
}

void Display::display_tree(){
    int index = 0;
    //struct TreeNode root;
    struct TreeNode* root = new TreeNode();
    root->level = 0;
    root->title = "root";
    generateTree(root,index,0);
    printTreeStructure(root);
    delete root;
}
void findTheDir(string dir,struct TreeNode* Node,struct TreeNode*&dirNode){
    if(Node->title==dir) dirNode = Node;
    else{
        if(Node->children.size()>0)
        {
            for(auto child:Node->children){
                findTheDir(dir, child,dirNode);
            }
        }
    } 
}

void  Display::display_dir_tree(string dir){//遍历树，返回node
    int index = 0;
    //struct TreeNode root;
    struct TreeNode* root = new TreeNode();
    root->level = 0;
    root->title = "root";
    generateTree(root,index,0);
    if(dir=="root"){
        display_tree();
    }
    else{
        struct TreeNode* dirNode = nullptr;
        findTheDir(dir,root,dirNode);
        if(dirNode==nullptr){
            cout<<"没有找到"<<dir<<"标题"<<endl;
        }
        else printTreeStructure(dirNode);
    }
    
    delete root;

}
