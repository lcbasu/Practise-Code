/*

http://www.codeproject.com/Articles/21909/Introduction-to-dynamic-two-dimensional-arrays-in

*/

#include <iostream>

using namespace std;

template <class T>
T **dynamicArray(int r, int c)
{
	T **tmp = new T *[r];
	for (int i = 0; i < r; ++i)
		tmp[i] = new T[c];
	return tmp;
}

template <class T>
void freeArray(T **dArray)
{
	delete [] *dArray;
	delete [] dArray;
}

int main()
{
	int r, c;
	cout << "No of Rows :\t";
	cin >> r;
	cout << "No of Columns :\t";
	cin >> c;	
	int **dArray = dynamicArray<int>(r, c);
	int num = 1;
	for (int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; j++)
			dArray[i][j] = num++;
	}
	for (int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; j++)
			cout << dArray[i][j] << "\t";
		cout << endl;
	}
	freeArray<int>(dArray);
}
