#include <iostream>

#define INFINITY 1000000

using namespace std;

void merge_sort(int [], int, int);
void merge(int [], int, int, int);

void merge_sort(int arr[], int p, int r)
{
	if(p < r)
	{
		int q = (p+r)/2;
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

void merge(int arr[], int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;

	int l_arr[n1+1];
	int r_arr[n2+1];

	l_arr[n1] = INFINITY;
	r_arr[n2] = INFINITY;

	int i,j;

	for(i=0; i<n1; i++)
		l_arr[i] = arr[p+i];

	for(j=0; j<n2; j++)
		r_arr[j] = arr[q+1+j];

	i=j=0;

	for(int k=p; k<=r; k++)
	{
		if(l_arr[i] <= r_arr[j])
		{
			arr[k] = l_arr[i];
			i = i+1;
		}
		else
		{
			arr[k] = r_arr[j];
			j=j+1;
		}
	}

}

int main()
{
	int a[] = {12,3,5,15,8,3,7};

	int size = sizeof(a)/sizeof(int);

	merge_sort(a, 0, size-1);

	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << "    ";
	}
	cout << endl;

	return 0;
}