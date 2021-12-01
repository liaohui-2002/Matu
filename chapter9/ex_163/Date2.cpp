#include<iostream>
using namespace std;

class Date {
public:
    Date(int y = 1996, int m = 1, int d = 1) {
        day = d;
        month = m;
        year = y;
        if (m>12 || m<1)
        {
            month = 1;
        }
        if (d>days(y, m))
        {
            cout << "Invalid day!" << endl;
            day = 1;
        }
    };
    int days(int y, int m);
    void display() {
        cout << year << "-" << month << "-" << day << endl;
    }
private:
    int year;
    int month;
    int day;
};
int Date::days(int year, int month)
{
    int num;
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            num = 31; break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                num = 29;
            else
                num = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            num = 30;
            break;
        default:
            num = 31;
    }
    return num;
}

ostream & operator << (ostream & out, Date &dt){
    dt.display();
    return out;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    Date dt(y, m, d);
    cout<<dt;
    return 0;
}