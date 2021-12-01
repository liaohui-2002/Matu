//
// Created by liaohui on 2021/11/21.
//

#ifndef MATU_VEHICLE_H
#define MATU_VEHICLE_H


#include <iostream>
using namespace std;
class Vehicle{
public:
    Vehicle(){
        cout<<"Vehicle constructor..."<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle destructor..."<<endl;
    }
    virtual void display() const =0;
    static Vehicle * createCar();
    static Vehicle * createTruck();
    static Vehicle * createBoat();
};


#endif //MATU_VEHICLE_H
