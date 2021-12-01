//
// Created by liaohui on 2021/11/30.
//

#include <iostream>
using namespace std;
#include <vector>
void Print(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        if(arr[i]!=0) {
            cout << arr[i] << " ";
        }
    }
}

void Sort(int *arr, int n)
{
    int mid = 0;
    int end = 0;
    for (; end < n; end++) {
        int currValue = arr[end];
        int j = end;
        if (currValue % 2 != 0 ) {  // Odd
            while (((j-1) >= mid) || (currValue < arr[j-1]) && ((j-1) >= 0)) {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = currValue;
            mid++;
        } else { // Even
            while ((j - 1) >= mid && currValue < arr[j-1]) {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = currValue;
        }
    }
}

int main(int argc, char *argv[])
{

    int arr[10];
    for(int i = 0;i<10;i++)
    {
        int temp;
        cin>>temp;
        if(temp <0)
        {
            break;
        }
        arr[i] = temp;
    }

    Sort(arr, sizeof(arr) / sizeof(arr[0]));

    Print(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}