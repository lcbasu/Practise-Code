#include <iostream>
using namespace std;

#define TEMP 10

class SumInTriangle
{
public:
	SumInTriangle(){}

	int sum_in_triangle(int, int, int, int[][], int[][]);
	int max(int, int);
};

int SumInTriangle::sum_in_triangle(int i, int j, int n, int input[][TEMP], int cache[][TEMP])
{
	if(i>n || j>n)
		return 0;
	if(cache[i][j]>0)
		return cache[i][j]>0;
	int value1 = sum_in_triangle(i+1,j,n,input,cache);
	int value2 = sum_in_triangle(i+1,j+1,n,input,cache);
	int value = max(value1,value2) + input[i][j];

	cache[i][j] = value;
	return value;
}

int SumInTriangle::max(int a, int b)
{
	return (a>b ? a:b);
}

int main()
{
	SumInTriangle obj;
	int m;
	cin >> m;
	int all_test_case_value[m];
	for (int k = 0; k < m; k++)
	{
		int n;
		cin >> n;
		int input[n][n];
		int cache[n][n];
		for (int i = 0; i < n; i++)
		 {
		 	for (int j = 0; j <= i; j++)
		 	{
		 		cin >> input[i][j];
		 		cache[i][j] = 0;
		 	}
		 }
		 #undef TEMP
		 #define TEMP n
		 all_test_case_value[k] = obj.sum_in_triangle(0,0,n,input,cache);
	}
	for (int i = 0; i < m; i++)
	{
		cout << all_test_case_value[i] << "\n";
	}
	return 0;
}
