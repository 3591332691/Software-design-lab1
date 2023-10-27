#ifndef CONTENTSCOMMAND_H
#define CONTENTSCOMMAND_H
#include <string>

class insertAction{
    public: 
    virtual void insert() = 0;
    insertAction();
    ~insertAction();
};

class insertCommand :public insertAction{
    public: 
    int lineNumber = 1;
    std::string str;
    void insert(int line_Number,std::string str_) override;
    void append_head();
    void append_tail();

};
class deleteAction{
    public: 
    virtual void delete_(int n) = 0;
    virtual void delete_(std::string s) = 0;
};

class deleteCommand :public deleteAction{
    public: 
    void delete_(int n) override;
    void delete_(std::string s) override;
    deleteCommand ();
};
#endif