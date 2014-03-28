#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX 100

using namespace std;

struct Guest
{
	int timestamp;
	char a_d;
};

bool myfunction(Guest const* G1, Guest const* G2)
{
	return G1->timestamp < G2->timestamp;
}

Guest* newGuest(int timestamp, char a_d)
{
	Guest *tmp = new Guest();
	tmp->timestamp = timestamp;
	tmp->a_d = a_d;
	return tmp;
}

int main()
{
	int arrival[] = {1800, 1807, 1900, 2000, 2010, 2015, 2100};
	int diparture[] = {1803, 1809, 1910, 2005, 2020,2031, 2200};

	int n1 = sizeof(arrival)/sizeof(int);
	int n2 = sizeof(diparture)/sizeof(int);

	vector<Guest *> result;

	char a_d;
	for(int i = 0; i < n1+n2; i++)
	{
		if(i<n1)
		{
			result.push_back(newGuest(arrival[i], 'a'));
		}
		else
		{
			result.push_back(newGuest(diparture[i-7], 'd'));
		}
	}

	sort(result.begin(), result.end(), myfunction);

	int maxGlassCount = INT_MIN;
	int count = 0;

	for(int i = 0; i < n1+n2; i++)
	{
		if(maxGlassCount < count)
			maxGlassCount = count;
		if(result[i]->a_d == 'a')
			count++;
		else if(result[i]->a_d == 'd')
			count--;
	}
	cout << "Min Glass needed : " << maxGlassCount << endl;
	return 0;
}
