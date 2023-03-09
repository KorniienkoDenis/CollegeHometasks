#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>

/*
	Task 2.
	1) Specify a one-dimensional array of 50 arbitrary numbers (positive and negative).
	2) Write a program that will display all elements of the array in a row on the screen
	   and save n (set by the user, 10<=n<=50) first elements of the array to a file.
	3) Write a program that reads the saved array from the file, display all its elements
	   on the screen, and performs the task of the variant.
	4) Conduct module and integration testing of the created algorithm.

	All numbers must be displayed in a different color than letters.

	Variant 10.
	In a one-dimensional array consisting of n integer elevents, calculate:

		1) the minimum array element by modulus;
		2) the sum of the modules of the array elements located after
		   the first element, which is equal to zero.

	Transform the array in such a way that the first half of the array
	contains elements that are in pair positions, while the second half
	contains elements that are in odd positions.
*/

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	srand(time(nullptr));
	
	const int size_arr1 = 50;
	int arr[size_arr1];

	int countOfSave;
	int minimumModul = 0;
	int sumModul = 0;

	for (int index = 0; index < size_arr1; index++)
		arr[index] = -15 + rand() % 19;

	std::cout << "Array: ";
	SetConsoleTextAttribute(handle, 3);

	for (int index = 0; index < size_arr1; index++)
		std::cout << arr[index] << " ";

	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "How many elements of array you want save in the file?\n";
	std::cout << "Input count over here -> ";
	std::cin >> countOfSave;

	std::cout << std::endl;

	std::ofstream fout("D:\\array.txt");
	if (!fout)
		std::cout << "Cannot open this file!\n";

	for (int index = 0; index < countOfSave; index++)
		fout << arr[index] << " ";

	fout.close();

	std::ifstream fin("D:\\array.txt");
	if (!fin)
		std::cout << "Cannot open this file!\n";

	std::cout << "Array: ";

	for (int index = 0; index < countOfSave; index++)
	{
		fin >> arr[index];
		std::cout << arr[index] << " ";
	}

	fin.close();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "1) The minimum elements modul in the array: ";
	
	SetConsoleTextAttribute(handle, 3);

	for (int index = 0; index < countOfSave; index++)
	{
		if (arr[index] == 0)
			arr[index] = 0;

		if (arr[index] < 0)
			arr[index] = arr[index] + -2 * arr[index];

		if (arr[index] > 0)
			arr[index] = arr[index];
	}

	for (int index = 0; index < countOfSave; index++)
	{
		for (int j = index + 1; j < countOfSave; j++)
		{
			if (arr[index] > arr[j])
			{
				minimumModul = arr[j];
			}
		}
	}

	std::cout << minimumModul << std::endl;

	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;
	std::cout << "2) The sum of the moduls of the array's elements which standing after the first zero element: ";

	for (int index = 0; index < countOfSave; index++)
	{
		if (arr[index] == 0)
		{
			for (int j = index + 1; j < countOfSave; j++)
			{
				if(arr[j] < 0)
					sumModul += (arr[j] + (-2) * arr[j]);

				if (arr[j] > 0)
					sumModul += arr[j];

				if (arr[j] == 0)
					sumModul += 0;
			}

			break;
		}
	}

	SetConsoleTextAttribute(handle, 3);
	std::cout << sumModul << std::endl;
	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;
	std::cout << "The first half of the array contains elements that are in pair position, " << std::endl;
	std::cout << "the second half of the array contains elements that are in odd position: ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Array: ";

	SetConsoleTextAttribute(handle, 3);

	for (int index = 0; index < countOfSave; index++)
		if (index % 2 == 0)
			std::cout << arr[index] << " ";

	for (int index = 0; index < countOfSave; index++)
		if (index % 2 == 1)
			std::cout << arr[index] << " ";

	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;

	return 0;
}