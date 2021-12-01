//
// Created by liaohui on 2021/11/30.
//

_#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int step=0;
    int ret = 1;
    long long int num=1;
    double pi=0;
    for (num = 1; num < 100000003; num += 2) {
        pi += 4*(1.0*ret * 1 / num);
        ret *= -1;
        step++;
    }
    cout << "steps=" << step << " PI=" << fixed << setprecision(5) << pi << endl;
    return 0;
}