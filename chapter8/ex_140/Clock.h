//
// Created by liaohui on 2021/10/29.
//

#ifndef MATU_CLOCK_H
#define MATU_CLOCK_H

#include<iostream>
using namespace std;
class Clock {
public:
    Clock(int h,int m, int s);
    void SetAlarm(int h,int m,int s);
    void run();
    void ShowTime();
private:
    int hour;   //时
    int minute;  //分
    int second;  //秒

    int Ahour;   //时（闹钟）
    int Aminute;  //分（闹钟）
    int Asecond;   //秒（闹钟）
};


#endif //MATU_CLOCK_H
