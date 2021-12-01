//
// Created by liaohui on 2021/11/21.
//

#include"CString.h"
#include <cstring>
int EditString::IsSubString(int start, const char* str)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        int k = start+i;
        for (j = 0; str[j] != '\0'; j++, k++)
        {
            if (str[j] != mystr[k]) break;
        }
        if (str[j] == '\0') return start + i;
    }
    return -1;
}

void EditString::EditChar(char s, char d)
{
    int i = 0;
    while (mystr[i])
    {
        if (mystr[i] == s)
            mystr[i] = d;
        i++;
    }
}

void EditString::EditSub( char* subs,char* subd)//提交时去掉const
{
    int i, j,len_s=strlen(subs),len_d=strlen(subd);
    for (i = 0; i < len; i++)
    {
        int k = i;
        for (j = 0; subs[j] != '\0'; j++, k++)
        {
            if (subs[j] != mystr[k]) break;
        }
        if (subs[j] == '\0')
        {
            int m = i + len_s;
            while (mystr[m-1])//注意
            {
                mystr[m + len_d - len_s] =mystr[m];
                m++;
            }
            m = 0;
            while (subd[m])
            {
                mystr[i + m] = subd[m];
                m++;
            }

            i += (len_d-1);
        }
    }
}

void EditString::DeleteChar(char ch)
{
    int i=0;
    while (mystr[i])
    {
        while (mystr[i] == ch)
        {
            int j = i;
            while (mystr[j])
            {
                mystr[j] = mystr[j + 1];
                j++;
            }
        }
        i++;
    }
}
void EditString::DeleteSub( char* sub)//提交时去掉const
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        int k =  i;
        for (j = 0; sub[j] != '\0'; j++, k++)
        {
            if (sub[j] != mystr[k]) break;
        }
        if (sub[j] == '\0')
        {
            int len = strlen(sub);
            int m = i+len;
            while (mystr[m-1])
            {
                mystr[m - len] = mystr[m];
                m++;
            }
        }
    }
}

