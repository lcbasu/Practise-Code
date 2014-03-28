#include <iostream>

using namespace std;

int no_of_set_bits(int M)
{
	int count = 0;
	while(M>0)
	{
		if(( M&1 ) == 1)
			count++;
		M>>=1;
	}
	return count;
}

int main()
{
	int T;
	cin >> T;

	int N;
	int G;
	while(T>0)
	{
		cin >> N >> G;
		int M;
		if(N<2)
			M = 1;
		else
		{
			int N1 = N-1;

			if(N1%2 == 0)
				N1 = N1/2;
			else
				N1 = (N1/2)+1;

			int M = 0;
			for (int i = 1; i <= N1; i++)
			{
				M = M + N;
				while(M >= 1000000007)
				{
					M = M - 1000000007;
				}
			}
		}
		int B = no_of_set_bits(M);
		if(B==G)
			cout << "CORRECT" << endl;
		else
			cout << "INCORRECT" << endl;
		T--;
	}
	return 0;
}