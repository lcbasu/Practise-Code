#include <iostream>

using namespace std;

template<class T>
bool binary_search(T [], T , int, int);

template<class T>
void quick_sort(T [], int, int);

template<class T>
int partition(T [], int, int);

template<class T>
void exchange(T *source_ptr, T *dest_ptr);


template<class T>
bool binary_search(T arr[], T key, int start_index, int end_index)
{
	if(start_index > end_index)
		return false;
	int mid = (start_index + end_index) / 2;
	if(arr[mid] == key)
		return true;
	else if(arr[mid] < key)
		binary_search(arr, key, mid+1, end_index);
	else
		binary_search(arr, key, start_index, mid-1);
}


template<class T>
void quick_sort(T arr[], int start_index, int end_index)
{
	if(start_index<end_index)
	{
		int partition_index = partition<T>(arr, start_index, end_index);
		quick_sort(arr, start_index, partition_index-1);
		quick_sort(arr, partition_index+1, end_index);
	}
}

template<class T>
int partition(T arr[], int start_index, int end_index)
{
	int x = arr[end_index];
	int i = start_index - 1;
	for(int j = start_index; j < end_index; j++)
	{
		if(arr[j] <= x)
		{
			i = i+1;
			exchange<T>(&arr[i], &arr[j]);
		}
	}
	exchange<T>(&arr[i+1], &arr[end_index]);
	return i+1;
}

template<class T>
void exchange(T *source_ptr, T *dest_ptr)
{
	T temp = *source_ptr;
	*source_ptr = *dest_ptr;
	*dest_ptr = temp;
}



int main()
{
	char a[] = {'c','a','d','e','t','r'};

	int size = sizeof(a)/sizeof(char);

	quick_sort<char>(a, 0, size-1);

	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << "    ";
	}
	cout << endl;

	char find = 's';

	bool is_present = binary_search<char>(a, find, 0, size-1);

	cout << find << " : " << ((is_present == true)? "is present." : "is not Present.") << endl;


	return 0;
}