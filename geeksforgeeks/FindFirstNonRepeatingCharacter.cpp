#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <map>

#define NO_OF_CHARS 256

using namespace std;

//Method 1
int first1(string str)
{
	map<char, int> myCountMap;
	for(int i = 0; i < str.size(); i++)
	{
		if(myCountMap.count(str[i]) == 0)
			myCountMap[str[i]] = 1;
		else
			myCountMap[str[i]] += 1;
	}
	for(int i = 0; i < str.size(); i++)
	{
		if(myCountMap[str[i]] == 1)
			return i;
	}
}


//Method 2

struct CountChar
{
	int count;
	int firstIndex;
};

CountChar *getArray(string str)
{
	CountChar *countArr = (CountChar*)calloc(sizeof(CountChar), NO_OF_CHARS);
	for (int i = 0; i < str.size(); ++i)
	{
		int index = str[i];
		countArr[index].count++;
		if(countArr[index].count == 1)
		{
			countArr[index].firstIndex = i;
		}
	}
	return countArr;
}

int first2(string str)
{
	CountChar *arr = getArray(str);
	int result = INT_MAX;
	for (int i = 0; i < NO_OF_CHARS; ++i)
	{
		if(arr[i].count == 1 && result > arr[i].firstIndex)
			result = arr[i].firstIndex;
	}
	return result;
}



int main()
{
	string str = "aabcc";
	cout << str[first1(str)] << endl;


	cout << str[first2(str)] << endl;
	return 0;
}
