#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}


int partition(char arr[], int start, int end)
{
	int x = arr[end];
	int i = start - 1;
	for(int j = start; j <= end-1; j++)
	{
		if(arr[j] <= x)
		{
			i = i + 1;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return i+1;
}

void quickSort(char arr[], int start, int end)
{
	if(start<end)
	{
		int q = partition(arr, start, end);
		quickSort(arr, start, q-1);
		quickSort(arr, q+1, end);
	}
}

int findCeilIndex(char *str, int firstIndex, int n)
{
	int ceilIndex;
	ceilIndex = firstIndex+1;

	for (int i = ceilIndex+1; i < n; i++)
	{
		if(str[i] >= str[firstIndex] && str[i] <= str[ceilIndex])
			ceilIndex = i;
	}
	return ceilIndex;
}

void reverse(char *str, int start, int end)
{
	while(start<=end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

void permutate(char *str, int n)
{
	quickSort(str, 0, n-1);
	cout << str << endl;
	bool done = false;
	while(!done)
	{
		int firstIndex;
		for(firstIndex = n-2; firstIndex >=0; firstIndex--)
		{
			if(str[firstIndex] < str[firstIndex+1])
				break;
		}
		if(firstIndex<0)
			done = true;
		if(!done)
		{
			int ceilIndex;
			ceilIndex = findCeilIndex(str, firstIndex, n);
			swap(&str[firstIndex], &str[ceilIndex]);
			reverse(str, firstIndex+1, n-1);
			cout << str << endl;
		}
	}
}


int main()
{
	char str[] = "mmd";
	permutate(str, 3);
	return 0;
}