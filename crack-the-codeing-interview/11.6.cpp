#include <iostream>

using namespace std;

#define R_MAX 50
#define C_MAX 50

bool search(int arr[R_MAX][C_MAX], int r, int c, int el)
{
	int rIndex = 0;
	int cIndex = c-1;
	while(rIndex < r && cIndex >= 0)
	{
		if(arr[rIndex][cIndex] == el)
			return true;
		else if(arr[rIndex][cIndex] > el)
			cIndex--;
		else
			rIndex++;
	}
	return false;
}

int main()
{
	int arr[R_MAX][C_MAX] = {{15, 20, 40, 85}, {20, 35, 80, 95}, {30, 55, 95, 105}, {40, 80, 100, 120}};
	int r = 4;
	int c = 4;
	if(search(arr, r, c, 55))
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	return 0;
}