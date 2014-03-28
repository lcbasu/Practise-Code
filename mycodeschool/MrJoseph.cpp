#include <iostream>

using namespace std;


int getIndex(int n, int k)
{
	if(n==1)
		return 1;
	return ((getIndex(n-1, k) + k-1)%n + 1);
}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;

		cout << getIndex(n, k) << endl;
	}
	return 0;
}