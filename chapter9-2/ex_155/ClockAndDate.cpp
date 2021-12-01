//
// Created by liaohui on 2021/11/21.
//

#include"ClockAndDate.h"

int Date::days(int year, int month)
{
    int monthsInLeapYear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int monthsInNormalYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return monthsInLeapYear[month - 1];
    else
        return monthsInNormalYear[month - 1];
}
void Date::NewDay()
{
    int m_d[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    day++;
    switch (month)
    {
        case 2:
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                if (day > 29)
                {
                    day = 1; month = 3;
                }
            }
            else
            {
                if (day > 28)
                {
                    day = 1; month = 3;
                }
            }
            break;
        default:
            if (day > m_d[month - 1])
            {
                day = 1; month++;
            }
            break;
    }
    if (month > 12)
    {
        month = 1; year++;
    }

}

class ClockWithDate :public Clock, public Date
{
public:
    ClockWithDate(int h, int m, int s, int year, int month, int day):Clock(h,m,s),Date(year,month,day){}
    virtual void showTime()
    {
        cout << "Now:" << hour << ":" << minute << ":" << second << endl << year << "-" << month << "-" << day << endl;
    }
    virtual void run()
    {
        second = second + 1;
        if (second > 59)
        {
            second = 0;
            minute += 1;
        }
        if (minute > 59)
        {
            minute = 0;
            hour += 1;
        }
        if (hour > 23)
        {
            hour = 0;
            NewDay();
        }

    }
};
Clock* Clock::createClockWithDate(int h, int m, int s, int year, int month, int day) {
    return new ClockWithDate(h, m, s, year, month, day);
}