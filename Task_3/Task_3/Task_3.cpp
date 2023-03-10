#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>

/*

	Task 3.
	1) Specify a two-dimensional array 13x13.
	2) Write a program that will display all elements
	   of the array in the form of a matrix with equal
	   columns on the screen and save them to a file.
	3) Write a program that reads the saved array from the file,
	   displays all its elements on the screen, and performs
	   the task of the variant.
	4) Conduct module and integration testing of the created algorithm.

	Variant 10.
	1) A matrix element is called a local minimum if it is strictly smaller
	than all of it's neighbors. Calculate the number of local minimals
	of a given matrix of size 13x13.

	2) Find the sum of modules of the elements which located above the main diagonal.

*/

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

bool isLocalMinimum(int matrix[][13], int row, int column, int maxRow, int maxColumn);
int SumModulElementsAboveTheMainDiagonal(int matrix[][13], int row, int column);

int main()
{
	srand(time(nullptr));

	int countMinimum = 0;

	const int row = 13;
	const int column = 13;

	int matrix[row][column];

	/* <----------------------------------------------------------------------------> */

	/* Initialize of the matrix with elements */
	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			matrix[indexRow][indexColumn] = -20 + rand() % 50;
		}
	}

	/* <----------------------------------------------------------------------------> */

	/* Output the matrix in the console */
	std::cout << "Matrix 13x13 : ";
	std::cout << std::endl;

	SetConsoleTextAttribute(handle, 3);
	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			std::cout << matrix[indexRow][indexColumn] << " \t";
		}

		std::cout << std::endl;
	}
	SetConsoleTextAttribute(handle, 7);

	/* <----------------------------------------------------------------------------> */

	/* Make a thread which wll write the matrix in the file */
	std::ofstream fout("D:\\matrix.txt");

	if (!fout)
		std::cout << "Cannot opent this file!\n";

	for(int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			fout << matrix[indexRow][indexColumn] << " \t";
		}

		fout << " " << std::endl;
	}

	fout.close();

	/* <----------------------------------------------------------------------------> */

	/* Make a thread which will display the matrix in the console from the file */
	std::ifstream fin("D:\\matrix.txt");

	if (!fin)
		std::cout << "Cannot open thsi file!\n";

	std::cout << std::endl;
	std::cout << "The matrix from the file matrix.txt: ";
	std::cout << std::endl;

	SetConsoleTextAttribute(handle, 3);
	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			fin >> matrix[indexRow][indexColumn];

			std::cout << matrix[indexRow][indexColumn] << " \t";
		}

		std::cout << std::endl;
	}
	SetConsoleTextAttribute(handle, 7);

	fin.close();

	/* <----------------------------------------------------------------------------> */

	/* By using a function isLocalMinimum, we to do the first condition in the task */
	std::cout << std::endl;
	std::cout << "1) Count of the locale minimums: ";

	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
		{
			if (isLocalMinimum(matrix, indexRow, indexColumn, row, column))
			{
				countMinimum++;
			}
		}
	}

	SetConsoleTextAttribute(handle, 3);
	std::cout << countMinimum;
	std::cout << std::endl;
	SetConsoleTextAttribute(handle, 7);
	/* <----------------------------------------------------------------------------> */

	/* By using a function SumModulElementsAboveTheMainDiagonal(), we to do the second condition in the task */
	std::cout << "2) The sum of moduls of the elements which located above the main diagonal: ";

	SetConsoleTextAttribute(handle, 3);
	std::cout << SumModulElementsAboveTheMainDiagonal(matrix, row, column);
	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;

	return 0;
}

/* A function which can find count of the locale minimum in the matrix */
bool isLocalMinimum(int matrix[][13], int indexRow, int indexColumn, int maxRow, int maxColumn)
{
	int value = matrix[indexRow][indexColumn];
	
	if ((indexColumn == 0) && value < matrix[indexRow][indexColumn + 1])
		return true;

	if ((indexColumn > 0 && value < matrix[indexRow][indexColumn - 1] &&
		value < matrix[indexRow][indexColumn + 1]))
		return true;

	return false;
}

/* A function which can find the sum of modules of the elements which located above the main diagonal */
int SumModulElementsAboveTheMainDiagonal(int matrix[][13], int row, int column)
{
	int sumModulAboveDiagonal = 0;

	for (int indexRow = 0; indexRow < row; indexRow++)
	{
		for (int indexColumn = indexRow + 1; indexColumn < column; indexColumn++)
		{
			if (matrix[indexRow][indexColumn] < 0)
				sumModulAboveDiagonal += matrix[indexRow][indexColumn] + (-2 * matrix[indexRow][indexColumn]);
			if (matrix[indexRow][indexColumn] > 0)
				sumModulAboveDiagonal += matrix[indexRow][indexColumn];
		}
	}

	return sumModulAboveDiagonal;
}