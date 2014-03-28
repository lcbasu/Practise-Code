#include <iostream>

using namespace std;

#define LARGE 1000


void merge(int *A, int *B, int eleInA, int eleInB)
{
	int lastIndex = (eleInA+eleInB) - 1;
	int indexB = eleInB - 1;
	int indexA = eleInA - 1;
	while(indexB >= 0)
	{
		if(A[indexA] > B[indexB])
		{
			A[lastIndex] = A[indexA];
			indexA--;
		}
		else
		{
			A[lastIndex] = B[indexB];
			indexB--;
		}
		lastIndex--;
	}
}

int main()
{
	int *A = new int[LARGE];
	int *B;
	int eleInA;
	int eleInB;
	cout << "Elements in A :\t";
	cin >> eleInA;
	cout << "Elements in B :\t";
	cin >> eleInB;
	cout << "Elements of array A :\t";
	B = new int[eleInB];
	for (int i = 0; i < eleInA; ++i)
	{
		cin >> A[i];
	}
	cout << "Elements of array B :\t";
	for (int i = 0; i < eleInB; ++i)
	{
		cin >> B[i];
	}
	cout << "\n\nArray A :\t";
	for (int i = 0; i < eleInA; ++i)
	{
		cout << A[i] << " ";
	}
	cout << "\nArray B :\t";
	for (int i = 0; i < eleInB; ++i)
	{
		cout << B[i] << " ";
	}	
	cout << "\nFinal Array :\t";
	merge(A, B, eleInA, eleInB);
	for (int i = 0; i < (eleInB+eleInA); ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}