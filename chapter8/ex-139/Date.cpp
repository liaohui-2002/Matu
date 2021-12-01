//
// Created by liaohui on 2021/11/17.
//

#include "Date.h"

Date::Date(int y, int m, int d) {

    year = y;
    if (m <= 0 || m > 12) {
        cout << "Invalid month!" << endl;
        month = 1;
    } else {
        month = m;
    }

    switch (month) {
        case 12:
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (d <= 0 || d > 31) {
                cout << "Invalid day!" << endl;
                day = 1;
            } else {
                day = d;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (d <= 0 || d > 30) {
                cout << "Invalid day!" << endl;
                day = 1;
            } else {
                day = d;
            }
            break;
        case 2:
            if (year % 4 == 0) {
                if (d <= 0 || d >29) {
                    cout << "Invalid day!" << endl;
                    day = 1;
                } else {
                    day = d;
                }
            } else {
                if (d <= 0 || d > 28) {
                    cout << "Invalid day!" << endl;
                    day = 1;
                } else {
                    day = d;
                }
            }
            break;
        default:
            break;
    }
}

void Date::NewDay() {
    switch (month) {
        case 12:
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (day >= 1 && day <= 30) {

                day++;
            } else {
                day = 1;
                if (month = 12) {
                    year++;
                    month = 1; }
                else {
                    month++;
                }
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day >= 1 && day <= 29) {

                day++;
            } else {
                day = 1;
                if (month = 12) {
                    year++;
                month = 1; }
                else {
                    month++;
                }
            }
        case 2:
            if (year % 4 == 0) {
                if (day >= 1 && day <= 28) {
                    day++;
                } else {
                    day = 1;
                    month++;
                }
            } else {
                if (day >= 1 && day <= 27) {

                    day++;
                } else {
                    day = 1;
                    month++;
                }
                break;
                default:
                    break;
            }

    }
}

    int Date::days(int year, int month){
        switch (month) {
            case 12:
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                return 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
                break;
            case 2:
                if (year % 4 == 0) {
                    return 29;
                } else {
                    return 28;
                }
                break;
            default:
                break;
        }
    }


    int main() {
        Date d(1993, 2, 28);
        d.display();
        d.NewDay();
        d.display();
        cout << d.days(2000, 2) << endl;
        return 0;
    }
