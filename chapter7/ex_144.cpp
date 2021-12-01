//
// Created by liaohui on 2021/11/30.
//
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1) {
        int space = 0;
        int i;
        while (n > 0) {
            for (i = 0; i < space; i++) {
                cout << " ";
            }
            for (i = 0; i < n; i++) {
                cout << "*";
            }
            space++;
            n -= 2;
            cout << "\n";
        }
        return 0;
    }
    else {
        cout << "error";
        return 0;
    }
}
