//
// Created by liaohui on 2021/11/18.
//

#ifndef MATU_CPOINT_H
#define MATU_CPOINT_H

#endif //MATU_CPOINT_H
#include <iostream>
using namespace std;
class Point{
public:
    Point(float xx, float yy){
        x = xx;
        y =yy;
    }
private:
    float x;
    float y;
};
//矩形
class Rectangle :public Point{
public:
    Rectangle(float xx,float yy,float w,float h);
    float Area();

private:
    float width;
    float high;
};
//圆
class Circle:public Point{
public:
    Circle(float xx,float yy,float r);

    float Area();

private:
    float radius;
};