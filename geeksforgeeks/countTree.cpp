#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

int countTree(int num)
{
	if(num <=1)
		return 1;
	else
	{
		int sum = 0;
		for (int root = 1; root <= num; root++)
		{
			int left = countTree(root - 1);
			int right = countTree(num - root);
			sum = sum + left*right;
		}
		return sum;
	}
}



int main()
{
	cout << countTree(4) << endl;
	return 0;
}
