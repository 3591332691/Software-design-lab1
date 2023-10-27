#ifndef CONTENTSCOMMAND_H
#define CONTENTSCOMMAND_H
#include <string>

class insertAction{
    public: 
    virtual void insert(int line_Number,std::string str_) = 0;
};

class insertCommand :public insertAction{
    public: 
    void insert(int line_Number,std::string str_) override;
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