#include <iostream>

using namespace std;

void display(int matrix[4][4]);

void rotate(int matrix[4][4])
{
	//transpose

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}

	cout << "After Transpose : " << endl;
	display(matrix);

	//rotate column	
	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4/2; j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[i][4-1-j];
			matrix[i][4-1-j] = tmp;
		}
	}	
}


void display(int matrix[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
}
int main()
{
	int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	cout << "Before :" << endl;
	display(matrix);

	rotate(matrix);

	cout << "After :" << endl;
	display(matrix);
	return 0;
}