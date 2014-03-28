#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char arr[100] = "a3b6c4d9";
	int t_arr_el = strlen(arr);
	int t_freq = 0;

	for(int i=1; i<t_arr_el; i = i+2)
		t_freq = t_freq + (arr[i]-'0');

	int de_comp_index = t_freq - 1;

	for(int temp_freq_index = t_arr_el - 1; temp_freq_index > 0; temp_freq_index = temp_freq_index -2)
	{
		int temp_freq = arr[temp_freq_index] - '0';
		
		int temp_char_index = temp_freq_index - 1;
		
		for(int k = 0; k<temp_freq; k++)
		{
			arr[de_comp_index-k] = arr[temp_char_index];
		}
		de_comp_index = de_comp_index - temp_freq;
	}

	for (int i = 0; i < t_freq; ++i)
	{
		cout << arr[i];
	}

	cout << endl;

	return 0;
}