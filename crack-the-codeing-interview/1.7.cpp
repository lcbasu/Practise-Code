#include <iostream>

using namespace std;

#define row 4
#define col 3

int matrix[row][col] = {{1, 0, 3}, {6, 7, 8}, {10, 11, 12}, {13, 14, 15}};
bool rowDone[4];
bool colDone[3];

void setZero(int matrix[row][col], int rowIndex, int colIndex)
{
	for (int i = 0; i < row; ++i)
	{
		matrix[i][colIndex] = 0;
	}
	for (int i = 0; i < col; ++i)
	{
		matrix[rowIndex][i] = 0;
	}	
}


void display(int matrix[row][col])
{
	for (int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
}

int main()
{
	for (int i = 0; i < row; ++i)
	{
		rowDone[i] = false;
	}
	for (int i = 0; i < col; ++i)
	{
		colDone[i] = false;
	}

	cout << "Before" << endl;

	display(matrix);

	for (int i = 0; i < row && !rowDone[i]; i++)
	{
		for(int j = 0; j < col && !colDone[j]; j++)
		{
			if(matrix[i][j] == 0 && !rowDone[i] && !colDone[j])
			{
				setZero(matrix, i, j);
				rowDone[i] = true;
				colDone[j] = true;
			}
		}
	}

	cout << "After" << endl;

	display(matrix);

	return 0;
}