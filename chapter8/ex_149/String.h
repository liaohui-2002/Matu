//
// Created by liaohui on 2021/11/18.
//

#ifndef MATU_STRING_H
#define MATU_STRING_H


#include <iostream>
#include <cstring>
using namespace std;
class String{
private:
    char *mystr;    //字符串
    int len;    //字符串长度
public:
    String(){
        len =0;
        mystr =NULL;
    }
    String(const char* p){
        len = strlen(p);
        mystr = new char[len+1];
        strcpy(mystr,p);
    }
    String(String &s){
        len = s.len;
        if (len !=0)
        {
            mystr = new char[len+1];
            strcpy(mystr,s.mystr);
        }
    }
    ~String(){
        if (mystr != NULL)
        {
            delete []mystr;
            mystr =NULL;
            len = 0;
        }
    }

    char *GetStr(){return mystr;}
    void ShowStr(){cout<<mystr;}

    bool IsSubstring(const char *str);
    bool IsSubstring(const String &str);
    int str2num();
    void toUppercase();
};


#endif //MATU_STRING_H
