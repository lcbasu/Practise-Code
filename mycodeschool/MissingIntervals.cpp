#include <iostream>

using namespace std;


int coinChange( int coinDesig[], int n, int p )
{
    int memory[p+1];

	for (int i = 0; i < p+1; ++i)
	{
		memory[i] = 0;
	}
 
	memory[0] = 1;
    for(int i=0; i<n; i++)
        for(int j=coinDesig[i]; j<=p; j++)
            memory[j] += memory[j-coinDesig[i]];
 
    return memory[p];
}



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n, k;
		int c;
		cin >> n >> k >> c;
		long long int start, end;
		long long int diff = 0;
		while(c--)
		{
			cin >> start >> end;
			diff = diff + end-start+1;
		}
		cout << k+diff << endl;
	}
	return 0;
}