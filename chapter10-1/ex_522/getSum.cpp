//
// Created by liaohui on 2021/11/22.
//

#include <iostream>

using namespace std;
//泛型编程思想
//函数模板
/*template<typename T>//声明创建模板 typename 表示其后面的符号是一种数据类型 可用class代替 T虚拟的通用类型
//函数 作为模板
void swap(T &a,T&b)
{
    T temp  = a;
    a = b;
    b = temp;
}*/
//自动类型推岛  直接 swap(a,b)
//显示指定类型 swap<int>(a,b)告诉编译器T是int

template<class T>
        T get_sum(T arr[],int length)
{
            if(length == 0){
                return NULL;
            }
            T sum;
            for(int i = 0;i<length;i++)
            {
                sum+= arr[i];
            }
            return  sum;
}
//普通函数和模板函数同名 优先调用模板函数
int main()

{

  int arr_int[6] = { 1, 2, 3, 4, 5, 6 };

  double arr_double[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

  cout << get_sum(arr_int, 6) << endl;

  cout << get_sum(arr_double, 6) << endl;

  return 0;
}