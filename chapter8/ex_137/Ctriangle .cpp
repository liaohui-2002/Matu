//
// Created by liaohui on 2021/11/17.
//
#include <iostream>
#include <cmath>

using namespace std;
class Ctriangle{
private:
   int a,b,c;

public:
    Ctriangle(int x,int y,int z)
    {
        this->a = x;
        this->b = y;
        this->c = z;
    }
    int GetPerimeter()  // 计算周长
    {
        return a+b+c;
    }
    void display()
    {
        cout<<"Ctriangle:"<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
    }
    double GetArea()
    {
        double p = (a+b+c)/2;
        double s = sqrt(p*(p-a)*(p-b)*(p-c));
        return s;
    }
};


int main(){
    double a,b,c;
    cin>>a>>b>>c;
    Ctriangle T(a,b,c);
    T.display();
    cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
    cout<<"Area:"<<T.GetArea()<<endl;
    return 0;
}