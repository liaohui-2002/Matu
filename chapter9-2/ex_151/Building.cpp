//
// Created by liaohui on 2021/11/19.
//

#include<iostream>
#include"Building.h"
using namespace std;

class TeachBuilding :public Building
{
private:
    char function0[20];
public:
    TeachBuilding(char* name, int floor, int room, int area,char* function) :Building(name, floor, room,area)
    {
        strcpy(function0, function);
    }
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "Floor:" << floor << endl;
        cout << "Room:" << room << endl;
        cout << "Area:" << area << endl;
        cout << "Function:" << function0 << endl;
    }
};
class DormBuilding :public Building
{
private:
    int people;
public:
    DormBuilding(char* name, int floor, int room, int area, int peoples) :Building(name, floor, room, area)
    {
        people = peoples;
    }
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "Floor:" << floor << endl;
        cout << "Room:" << room << endl;
        cout << "Area:" << area << endl;
        cout << "Peoples:" << people << endl;
    }

};

Building* Building::createTeachBuilding(char* name, int floor, int room, int area, char* function) {
    return  new TeachBuilding(name, floor, room, area, function);
}

Building* Building::creatDormBuilding(char* name, int floor, int room, int area, int peoples) {
    return new DormBuilding(name, floor, room, area, peoples);
}
