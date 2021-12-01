//
// Created by liaohui on 2021/11/19.
//

#ifndef MATU_SHAPEFACTORY_H
#define MATU_SHAPEFACTORY_H


class ShapeFactory {
public:
    ShapeFactory(){};
    virtual ~ShapeFactory(){};

    virtual float Circumstance(){return 0;};
    ShapeFactory *Create(float a,float b,float c);
    ShapeFactory *Create(float a,float b,float c,float d);
    ShapeFactory *Create(float r);
};


#endif //MATU_SHAPEFACTORY_H
