//
// Created by liaohui on 2021/11/21.
//

#include"Clock.h"

class NewClock :public Clock {
    int hour, minute, second;
public:
    NewClock(int h, int m, int s) : Clock(h, m, s) {

        hour = getHour();
        minute = getMinute();
        second = getSecond();
    }
    void showTime() {

        if (hour < 12)
        {
            cout << "Now:" << hour << ":" << minute << ":" << second << "AM" << endl;
        }
        else
        {
            cout << "Now:" << hour - 12 << ":" << minute << ":" << second << "PM" << endl;
        }
    }
    void run() {
        second = second + 1;
        if (second>59)
        {
            second = 0;
            minute += 1;
        }
        if (minute>59)
        {
            minute = 0;
            hour += 1;
        }
        if (hour>23)
        {
            hour = 0;
        }
    }
};
Clock* Clock::createNewClock(int h, int m, int s) {
    return new NewClock(h, m, s);
}


