//
// Created by liaohui on 2021/10/29.
//

#include "Clock.h"

Clock::Clock(int h, int m, int s) {
    if (h < 0 || h > 24) {
        h = 0;
    }
    if (m < 0 || m > 60) m = 0;
    if (s < 0 || s > 60) s = 0;
    this->hour = h;
    this->minute = m;
    this->second = s;
}

void Clock::SetAlarm(int h, int m, int s) {
    if ( h > 24) {
        h = 0;
    }
    if ( m > 60) m = 0;
    if (s > 60) s = 0;
    Ahour = h;
    Aminute = m;
    Asecond  = s;
}

void Clock::run() {
    this->second++;
    if(this->hour == Ahour&& this->minute ==Aminute&&this->second == Asecond)
    {
        cout<<"Plink!plink!plink!..."<<endl;
    }

}

void Clock::ShowTime() {
    cout << "Now:" << hour << ":" << minute << ":" << second << endl;
}
int main()
{
    Clock *c = new Clock(2,3,4);
    c->SetAlarm(2,3,5);
    c->run();
    return 0;
}