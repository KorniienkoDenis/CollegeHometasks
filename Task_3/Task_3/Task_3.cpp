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

int main()
{
	srand(time(nullptr));

	const int row = 13;
	const int column = 13;

	int matrix[row][column];



	for (int indexRow = 0; indexRow < row; indexRow++)
		for (int indexColumn = 0; indexColumn < column; indexColumn++)
			matrix[indexRow][indexColumn] = -20 + rand() % 50;



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



	std::ifstream fin("D:\\matrix.txt");

	if (!fout)
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





	return 0;
}
