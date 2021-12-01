//
// Created by liaohui on 2021/10/29.
//
//统计字符串出现的次数
#include <iostream>
#include "string.h"
using namespace std;
int SubStrNum(char * str,char * substr);
int main()
{
    int res = SubStrNum("helloll","ll");
    cout<<"match times="<<res<<endl;
    return 0;
}
int SubStrNum(char * str,char * substr)
{
    int num = 0;
    while(strlen(str)>0)
    {
        if(strncmp(str,substr,strlen(substr)) == 0)
        {
            num++;
            str+=strlen(substr);
        }
        else{
            str++;
        }
    }
    return num;
}