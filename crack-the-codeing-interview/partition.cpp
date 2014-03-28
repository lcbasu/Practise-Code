#include <iostream>

using namespace std;

void exchange( int *source, int *destn)
{
	int temp = *source;
	*source = *destn;
	*destn = temp;
}

void partition(int *arr, int p, int r)
{
	int x = 0;

	int i = p -1;

	for (int j = 0; j <= r ; j++)
	{
		if(arr[j] > x)
		{
			i = i + 1;
			exchange(&arr[i], &arr[j]);
		}
	}

	for (int i = 0; i <=r; ++i)
	{
		cout << arr[i] << "    ";
	}
	cout << endl;
}

void threeWayPartition(int data[], int size, int low, int high)
{
	int p = -1;
	int q = size;
	for (int i = 0; i < q;)
	{
		if (data[i] < low)
		{
			swap(data[i], data[++p]);
			++i;
		}
		else if (data[i] >= high)
		{
			swap(data[i], data[--q]);
		}
		else
		{
			++i;
		}
	}
	for (int i = 0; i <=high; ++i)
	{
		cout << data[i] << "    ";
	}
	cout << endl;
}


int main()
{
	int a[] = {-2, 13, 4, -3, -2, 1, 5, -3};
	int size = sizeof(a)/sizeof(a[0]);

	partition(a, 0, size-1);

	int b[] = {-2, 13, 4, -3, -2, 1, 5, -3};
	int size_b = sizeof(b)/sizeof(b[0]);
	
	threeWayPartition(b, size_b, 0, size_b-1);

	return 0;
}