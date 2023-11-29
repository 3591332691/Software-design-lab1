
#ifndef FILE_H
#define  FILE_H
#include <string>
#include <vector>
using namespace std;
class File{
    private:
        string filename;//其实是文件路径
        int working_time;//以min为单位
        int start_time;//load这个文件时的时间(以min为单位)
    public:
        int getWorkingTime();
        void setFileName(string a);
        string getFileName();
        void setStartTime();
        void storeWorkingTime();
        File()
        {
            working_time = 0;
            start_time = 0;
        };
};

#endif