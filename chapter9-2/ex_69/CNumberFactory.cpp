//
// Created by liaohui on 2021/11/19.
//

#include "CNumberFactory.h"
#include<iostream>
#include"CNumberFactory.h"
using namespace std;

class CNum :public CNumberFactory
{
private:
    int value;
public:
    CNum() {}
    CNum(int a)
    {
        value = a;
    }
    virtual void SetValue(int number)
    {
        value = number;
    }
    virtual int GetValue() { return value;}
    virtual void Add(int number) { value += number; }
    virtual void Sub(int number) { value -= number; }
};
CNumberFactory* CNumberFactory::Create()
{
    return new CNum();
}


