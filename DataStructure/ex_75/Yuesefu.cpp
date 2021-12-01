//
// Created by liaohui on 2021/11/30.
//
#include<math.h>
#include<string.h>
#include<iomanip>
using namespace std;
//定义结点
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
float N, K, M;//N:总人数,K:剩余人数,M:间隔人数
//创建链表结点
Node* CreatNode(int num)
{
    Node* p = (Node*)malloc(N);
    if (p != NULL)
    {
        p->data = num;
        p->next = NULL;
        return p;
    }
    else
    {
        printf("结点创建失败");
        return p;
    }
}
//创建循环链表
Node* CreatJosefList(int num)
{
    Node* head = NULL, * p = NULL, * tail = NULL;
    head = (Node*)malloc(N);
    tail = (Node*)malloc(N);
    for (int i = 1;i <= num;i++)
    {
        p = CreatNode(i);
        if (i == 1)
            head = p;
        else
        {
            tail->next = p;
        }
        tail = p;
    }
    if (head != NULL)
    {
        tail->next = head;
    }
    return head;
}
//约瑟夫环
void JosefList(int N, int K, int M)
{
    Node* head = CreatJosefList(N);
    Node* tail;
    int len = N;//链表长度
    //删除
    while (len > K)
    {
        //间隔M个人
        for (int i = 0;i < M - 1;i++)
        {
            head = head->next;
        }
        //删除第M+1个
        tail = head->next;
        head->next = tail->next;
        head = head->next;//删除完成
        len -= 1;//剩下的人数
    }
    //为数组a动态分配内存K(a是用来存放剩下的人，然后进行升序排序输出的)
    int* a = NULL;
    if (K <= 0) { printf("error");exit(-1); }
    a = (int*)malloc(sizeof(int) * K);
    if (NULL == a) { printf("error");exit(-1); }
    //把链表里剩下的人存到a里
    for (int i = 0;i < K;i++)
    {
        a[i] = head->data;
        head = head->next;
    }
    //对a升序排序
    for (int i = 0, t;i < K;i++)
        for (int j = 0;j < K - 1 - i;j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    //输出
    for (int i = 0;i < K;i++)
    {
        cout << a[i];
        if (i != K - 1)cout << ',';
    }
}
int main()
{
    cin >> N >> K >> M;
    if (N <= 0 || K < 0 || M < 0 || K>N || (int)N != N || (int)K != K || (int)M != M)
    {
        cout << "ERROR"; return 0;
    }//判断是否为错误输入
    if (K == 0)
    {
        cout << 0;return 0;
    }//如果剩余人数是0，则无需进行计算，直接输出0
    JosefList(N, K, M);
}
