#include <iostream>
#include <math.h>

#define SENTINEL 100000000

using namespace std;

class MeregeSort
{
public:
	MeregeSort(){}

	void merge_sort(int[], int, int);
	void merge(int[], int, int, int);
};

void MeregeSort::merge(int a[], int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;

	int left[n1+1];
	int right[n2+1];

	int i=0,j=0;

	for(i=0; i<n1; i++)
		left[i] = a[p+i];

	for (j = 0; j < n2; j++)
		right[j] = a[q+j+1];

	left[n1] = SENTINEL;
	right[n2] = SENTINEL;

	i = 0;
	j = 0;

	for (int k = p; k <= r; k++)
	{
		if(left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
	}
}

void MeregeSort::merge_sort(int a[], int p, int r)
{
	if(p<r)
	{
		int q = int(floor((p+r)/2));

		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge(a, p, q, r);
	}
}

int main()
{
	MeregeSort mSort;

	int n;

	cout << "Number of elements : ";
	cin >> n;
	cout << "\n";

	int a[n];

	cout << "Enter " << n << " elements : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "Numbers before sorting : \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << "\n";

	mSort.merge_sort(a,0,n-1);

	cout << "Numbers after sorting : \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
