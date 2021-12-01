//
// Created by liaohui on 2021/11/21.
//

#include "Shape.h"
class Rectangle : public Shape {
private:
    double width;
    double length;
public:
    Rectangle(double l,double w){
        width = w;
        length = l;
    }
    ~Rectangle(){}
    double GetPerimeter() override//周长
    {
        return 2*(width+length);
    }
    double GetArea() override
    {
        return width*length;
    }

};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r){
        radius = r;
    }
    ~Circle(){}
    double GetPerimeter() override//周长
    {
        return 2*3.14*radius;
    }
    double GetArea() override
    {
        return 3.14*radius*radius;
    }
};

Shape *Shape::createRectangle(double length, double width) {

    return new Rectangle(length,width);
}

Shape *Shape::createCircle(double radius) {

    return new Circle(radius);
}
