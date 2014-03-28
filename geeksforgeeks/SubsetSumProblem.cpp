#include <iostream>

using namespace std;

bool isSubSet(int set[], int n, int sum)
{
	if(sum == 0)
		return true;	
	if(n == 0 && sum > 0)
		return false;
	if(set[n-1] > sum)
		return isSubSet(set, n-1, sum);
	return (isSubSet(set, n-1, sum-set[n-1]) || isSubSet(set, n-1, sum));
}

int main()
{
	int set[] = {3, 34, 12, 4, 18, 9};
	int sum = 16;
	if(isSubSet(set, 6, sum))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}