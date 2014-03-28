#include <iostream>
#include <string>

using namespace std;

bool isAnagram(int ascii[], string str1, string str2)
{
	bool result = true;
	int s1 = str1.size();
	int s2 = str2.size();
	if(s1 != s2)
		result = false;
	else
	{
		for (int i = 0; i < s1; ++i)
		{
			int tmp = str1[i];
			ascii[tmp]++;
		}
		for (int i = 0; i < s2; ++i)
		{
			int tmp = str2[i];
			if(--ascii[tmp] < 0)
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

char compare(string str1, string str2)	//	l -> Less Than, g -> Greater Than, e -> Equal To
{
	char result;
	if(str1.size() < str2.size())
		result = 'l';
	else if(str1.size() > str2.size())
		result = 'g';
	else
	{
		int ascii[256];
		for (int i = 0; i < 256; ++i)
		{
			ascii[i] = 0;
		}
		if(isAnagram(ascii, str1, str2))
			result = 'e';
		else
		{
			for (int i = 0; i < str1.size(); ++i)
			{
				if(str1[i] < str2[i])
				{
					result = 'l';
					break;
				}
				else if(str1[i] > str2[i])
				{
					result = 'g';
					break;
				}
			}
		}
	}
	return result;
}

void swap(string *str1, string *str2)
{
	string tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

int partition(string arr[], int p, int r)
{
	string x = arr[r];
	int i = p-1;
	for (int j = p; j < r; j++)
	{
		char cmp = compare(arr[i], x);
		if(cmp == 'l' || cmp == 'e')
		{
			i = i + 1;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}


void quicksort(string arr[], int p, int r)
{
	if(p<r)
	{
		int q = partition(arr, p, r);
		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
}

void sort(string arr[], int n)
{
	quicksort(arr, 0, n-1);
}


int main()
{
	string arr[] = {"Lokesh","Lokesh", "okeshL", "keshol"};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Before\n";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	sort(arr, n);
	cout << "After\n";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;	
	return 0;
}
