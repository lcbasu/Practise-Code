/*
*	Given a list L of integers, a1 , a2 , . . . , an , and an integer M ,
*	describe an algorithm that finds the largest subset of L whose sum 
*	is at most M . Your algorithm should run in linear time.
*/

#include <iostream>


using namespace std;


void largest_subset(int arr[], int size)
{
	int max_so_far = 0;
	int max_ending_here = 0;
	int start_index = 0;
	int end_index = 0;
	for(int i=0; i<size; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		if(max_ending_here<0)
		{
			max_ending_here = 0;
			start_index = i+1;
		}
		else if(max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			end_index = i;
		}
	}
	cout <<  "Max sum is : " << max_so_far << " between the array index " << start_index << " and " << end_index << endl;
}

int main()
{
	int a[] = {-2, -13, 4, -3, -2, 1, 5, -3};
	int size = sizeof(a)/sizeof(a[0]);
	largest_subset(a,size);

	return 0;
}