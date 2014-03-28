#include <iostream>
#include <cmath>

using namespace std;

int totalOnes(int n)
{
	int count = 0;
	int i = 0;
	while(n != 0)
	{
		if((n & (1 << i)) != 0)
			count++;

		n = n & ~(1 << i);
		i++;
	}
	return count;
}

int game(int n)
{
	int totalTurns = 0;
	bool found = false;	//found another beautiful number
	while(true)
	{
		int totalOnesIn_N = totalOnes(n);
		int k = 0;
		while(pow(2, k) < n)
		{
			int m = n - pow(2, k);
			int totalOnesIn_M = totalOnes(m);
			if(totalOnesIn_M == totalOnesIn_N)
			{
				n = m;
				found = true;
				totalTurns++;
				break;	//since plays optimal so least value of k should break the loop
			}
			k++;
		}
		if(!found)
			break;
		found = false;	//reseting the value for next turn
	}
	return totalTurns;
}

int main()
{
	int n = 7;
	if(game(n)%2 == 0)
		cout << "Second Player Wins" << endl;
	else
		cout << "First Player Wins" << endl;
	return 0;
}
