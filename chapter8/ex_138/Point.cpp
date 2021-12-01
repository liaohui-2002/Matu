//
// Created by liaohui on 2021/11/17.
//
#include <iostream>
#include <cmath>

using namespace std;

class Point {

private:

    int x;
    int y;

public:
    Point(int a, int b) {
        x = a;
        y = b;
    }

    double  Distance(Point point) {
        int e = x  - point.x;
        int l = y - point.y;
        double  s = sqrt((float)(e*e+l*l));
        return s;
    }
};

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Point A(a, b), B(c, d);
    cout << A.Distance(B) << endl;
    return 0;
}