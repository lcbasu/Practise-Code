#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	int n = 7;
	bool *guest = new bool[n];

	memset(guest, false, n);

	int arrival[] = {1800, 1807, 1900, 2000, 2010, 2015, 2100};
	int diparture[] = {1803, 1809, 1910, 2005, 2020,2031, 2200};

	int minGlass = 0;

	for(int i = 0; i < n; i++)
	{
		if(guest[i] == false)
		{
			minGlass++;
			int i_tmp = i;
			guest[i] = true;
			for(int j = i+1; j < n; j++)
			{
				if(guest[j] == false && diparture[i_tmp] <= arrival[j])
				{
					guest[j] = true;
					i_tmp = j;
				}
			}
		}
	}
	printf("%d\n", minGlass);
}
