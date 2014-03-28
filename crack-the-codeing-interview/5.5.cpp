#include <iostream>

using namespace std;

int bitsRequired(int A, int B)
{
	int C = A^B;
	int count = 0;
	while(C!=0)
	{
		if((C&1) != 0)
			count++;
		C >>= 1;
	}
	return count;
}

int main()
{
	int A, B;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	cout << "Total bit required for conversion : " << bitsRequired(A, B) << endl;
	return 0;
}