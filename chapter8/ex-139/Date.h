//
// Created by liaohui on 2021/11/17.
//

#ifndef MATU_DATE_H
#define MATU_DATE_H
#include <iostream>
using namespace std;

class Date {
private:
    int year; //年
    int month; //月
    int day;  // 日
public:
    Date(int y,int m,int d);
    int days(int year,int month);
    void NewDay();
    void display()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }

};


#endif //MATU_DATE_H
