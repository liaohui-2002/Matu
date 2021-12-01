//
// Created by liaohui on 2021/11/21.
//

#ifndef MATU_LOCATION_H
#define MATU_LOCATION_H


#include <iostream>
using namespace std;
class Location{
public:
    Location(int xx,int yy){
        x =xx;
        y =yy;
    }
    Location &operator +(Location &offset);
    Location &operator -(Location &offset);

    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};


#endif //MATU_LOCATION_H
