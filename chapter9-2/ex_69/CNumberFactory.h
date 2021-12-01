//
// Created by liaohui on 2021/11/19.
//

#ifndef MATU_CNUMBERFACTORY_H
#define MATU_CNUMBERFACTORY_H


class CNumberFactory {
public:
    virtual void Add(int number) {};
    virtual void Sub(int number) {};
    virtual int GetValue() {return -1;};

    virtual void SetValue(int number) {};
    CNumberFactory *Create();
};


#endif //MATU_CNUMBERFACTORY_H
