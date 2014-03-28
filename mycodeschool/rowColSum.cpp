#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int N, W;
		int X;
		char R_C;
		cin >> N >> W;
		cin >> X >> R_C;
		long long int a1, an, n;
		long long int sum = 0;
		if(R_C == 'C')
		{
			n = (N-X)/W + 1;
			a1 = X;
			an = a1 + (n-1)*W;
			sum = (n*(a1+an))/2;
		}
		else if(R_C == 'R')
		{
			a1 = 1 + W*(X-1);
			an = a1 + (W-1);
			n = W;
			while(!(an <= N))
			{
				an--;
				n--;
			}
			sum = (n*(a1+an))/2;
		}
		cout << sum << endl;
	}
	return 0;
}