#include <iostream>
#include <map>

using namespace std;

map<int, int> trackCount;

void track(int x)
{
	if(trackCount.count(x) == 0)
		trackCount[x] = 1;
	else
		trackCount[x] += 1;
}

int getRankOfNumber(int x)
{
	int rank = 0;
	map<int, int>::iterator it;
	for(it = trackCount.begin(); it != trackCount.end(); it++)
	{
		if(it->first < x)
			rank = rank + (*it).second;
		if((it->first == x) && (it->second > 0))
			rank = rank + it->second - 1;
	}
	return rank;
}

int main()
{
	int d;
	while(true)
	{
		cout << "No :\t";
		cin >> d;
		cout << "Tracking :\t" << d << endl;
		track(d);
		cout << "Rank :\t" << getRankOfNumber(d) << endl;
		cout << endl;
	}
	return 0;
}