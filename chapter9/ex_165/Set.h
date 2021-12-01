//
// Created by liaohui on 2021/11/18.
//

#ifndef MATU_SET_H
#define MATU_SET_H


#include <iostream>
using namespace std;
class Set{
private:
    int n;
    int * pS; //集合元素
public:
    Set(){n = 0;pS =NULL;}
    Set(Set &s){
        n = s.n;
        if (n !=0)
        {
            pS= new  int[n+1];
            for (int i =1;i<=n;i++) //集合的下标从1开始，集合中不能有重复元素
                pS[i] = s.pS[i];
        }
    }
    ~Set(){
        if (pS)
        {
            delete []pS;
            pS = NULL;
            n =0;
        }
    }
    void ShowElement()const{ //输出集合的元素
        int temp = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(pS[i] > pS[j])
                {
                    temp = pS[i];
                    pS[i] = pS[j];
                    pS[j] = temp;
                }
            }
        }
        cout<<"{";
        for(int i =1;i<n;i++)
            cout <<pS[i]<<",";
        if (IsEmpty())
            cout<<"}"<<endl;
        else cout<<pS[n]<<"}"<<endl;
    }
    bool IsEmpty()const{return n?false:true;} //判断集合是否为空
    int size(){return n;}
    bool IsElement(int e)const {
        for (int i =1;i<=n;i++)
            if (pS[i] ==e)
                return true;
        return  false;
    }
    bool operator <=(const Set &s)const;//this <= s判断当前集合是否包于集合s
    bool operator ==(const Set &s)const; //判断集合是否相等
    Set & operator +=(int e);    // 向集合中增减元素e
    Set & operator -=(int e);    //删除集合中的元素e

    Set operator |(const Set &s)const;  //集合并
    Set operator &(const Set &s)const;//集合交
    Set operator -(const Set &s)const; //集合差
};

#endif //MATU_SET_H
