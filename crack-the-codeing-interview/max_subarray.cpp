#include <iostream>


using namespace std;


int max_sum_sub_arr(int arr[], int size)
{
	int max_so_far = 0;
	int max_ending_here = 0;
	for(int i=0; i<size; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		if(max_ending_here<0)
			max_ending_here = 0;
		else if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}

int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(a)/sizeof(a[0]);
	cout << max_sum_sub_arr(a,size) << endl;

	return 0;
}