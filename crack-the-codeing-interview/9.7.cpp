#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[5][5], int n)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void paintFill(int arr[5][5], int i, int j, int num)
{
    if(i < 0 || j < 0 || i >= 5 || j >= 5)
        return;
    if(arr[i][j] == num)
    {
        arr[i][j] = 99;
        paintFill(arr, i+1, j, num);
        paintFill(arr, i-1, j, num);
        paintFill(arr, i, j+1, num);
        paintFill(arr, i, j-1, num);
    }
}

int main()
{
    int arr[5][5] = {{1,2,2,2,5},{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
    print(arr, 5);
    paintFill(arr, 0, 1, 2);
    print(arr, 5);
    return 0;
}
