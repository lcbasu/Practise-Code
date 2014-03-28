#include <iostream>

using namespace std;

void moveZeros(int *arr, int n)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] != 0)
		{
			arr[count] = arr[i];
			count++;
		}
	}
	for(int i = count; i < n; i++)
	{
		arr[i] = 0;
	}
}

int main()
{
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    moveZeros(arr, n);
    cout << "After : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
