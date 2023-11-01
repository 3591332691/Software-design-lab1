#ifndef SHOWCOMMAND_H
#define SHOWCOMMAND_H
#include <string>
#include <vector>

struct TreeNode {
    std::string title;
    std::vector<struct TreeNode*> children;
    int level;
    struct TreeNode* parent;
};
class ShowCommand{
    public: 
    virtual void display() = 0;
};

class Display : public ShowCommand {
    public:
    void display() override;
    void display_tree();
};

#endif