#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
void swapInt(T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(string flightNo[], float depTime[], int flightDuration[], int price[], int n)
{
	if(n<=1)
		return;
	for (int i = 0; i < n; ++i)
	{
		bool noSwapping = false;
		for(int j = 0; j < n-i-1; j++)
		{
			if(price[j] > price[j+1])
			{
				noSwapping = false;
				swap<string>(flightNo[j], flightNo[j+1]);
				swap<float>(depTime[j], depTime[j+1]);
				swap<int>(flightDuration[j], flightDuration[j+1]);
				swap<int>(price[j], price[j+1]);
			}
			else if(price[j] == price[j+1] && flightDuration[j] > flightDuration[j+1])
			{
				noSwapping = false;
				swap<string>(flightNo[j], flightNo[j+1]);
				swap<float>(depTime[j], depTime[j+1]);
				swap<int>(flightDuration[j], flightDuration[j+1]);
				swap<int>(price[j], price[j+1]);
			}
			else if(price[j] == price[j+1] && flightDuration[j] == flightDuration[j+1] && depTime[j] > depTime[j+1])
			{
				noSwapping = false;
				swap<string>(flightNo[j], flightNo[j+1]);
				swap<float>(depTime[j], depTime[j+1]);
				swap<int>(flightDuration[j], flightDuration[j+1]);
				swap<int>(price[j], price[j+1]);
			}						
		}
		if(noSwapping)
			break;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string *flightNo = new string[n];
		float *depTime = new float[n];
		int *flightDuration = new int[n];
		int *price = new int[n];
		for (int i = 0; i < n; ++i)
		{
			string tmp;
			float tmpDep;
			cin >> flightNo[i] >> tmp >> flightDuration[i] >> price[i];
			stringstream ss;
			ss << tmp.substr(0, 2);
			ss >> tmpDep;
			depTime[i] = tmpDep;
			ss.str("");
			ss << tmp.substr(3, 2);
			ss >> tmpDep;
			depTime[i] = depTime[i] + (tmpDep/100);	//converting departing time from the format 08:29 to 8.29 (float version)
		}
		sort(flightNo, depTime, flightDuration, price, n);
		int i;
		for (i = 0; i < 2; ++i)
		{
			cout << flightNo[i] << " ";
		}
		cout << flightNo[i] << endl;
	}
	return 0;
}