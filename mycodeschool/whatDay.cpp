#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	while(t--)
	{
		string day;
		int targetYr;
		cin >> day >> targetYr;
		long long int totalDays = 0;
		for (int i = 1600; i < targetYr; i++)
		{
			if(i % 400 == 0)
				totalDays = totalDays + 366;
			else if(i%100 == 0)
				totalDays = totalDays + 365;
			else if(i%4 == 0)
				totalDays = totalDays + 366;
			else
				totalDays = totalDays + 365;
		}
		int dayIndex;
		for (int i = 0; i < 7; ++i)
		{
			if(days[i].compare(day) == 0)
			{
				dayIndex = i;
				break;
			}
		}
		int newIndex = (dayIndex + (totalDays%7))%7;
		cout << days[newIndex] << endl;
	}
	return 0;
}