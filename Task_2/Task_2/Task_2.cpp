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
	int sumModul = 0;

	/* <----------------------------------------------------------------------------> */

	/* Initialize of the array with elements */
	for (int index = 0; index < size_arr1; index++)
		arr[index] = -20 + rand() % 60;

	/* <----------------------------------------------------------------------------> */

	/* Output the array in the console */
	std::cout << "Array: ";
	SetConsoleTextAttribute(handle, 3);

	for (int index = 0; index < size_arr1; index++)
		std::cout << arr[index] << " ";
	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;
	std::cout << std::endl;

	/* <----------------------------------------------------------------------------> */

	/* Ask the user input count of the elements which will be save in the file */
	do
	{
		std::cout << "How many elements of array you want save in the file? (10 to 50)\n";
		std::cout << "Input count over here -> ";
		std::cin >> countOfSave;

		if (std::cin.fail())
		{
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

	} while (countOfSave <= 9 || countOfSave >= 51);

	std::cout << std::endl;

	/* <----------------------------------------------------------------------------> */

	/* Make a thread which will write the array */
	std::ofstream fout("D:\\array.txt");
	if (!fout)
		std::cout << "Cannot open this file!\n";

	for (int index = 0; index < countOfSave; index++)
		fout << arr[index] << " ";

	fout.close();

	/* <----------------------------------------------------------------------------> */

	/* Make a thread which will display the array in the console */
	std::ifstream fin("D:\\array.txt");
	if (!fin)
		std::cout << "Cannot open this file!\n";

	std::cout << "Array: ";
	SetConsoleTextAttribute(handle, 3);

	for (int index = 0; index < countOfSave; index++)
	{
		fin >> arr[index];
		std::cout << arr[index] << " ";
	}

	SetConsoleTextAttribute(handle, 7);

	fin.close();

	std::cout << std::endl;
	std::cout << std::endl;

	/* <----------------------------------------------------------------------------> */

	/* The first condition in the task */
	std::cout << "1) The minimum elements modul in the array: ";
	SetConsoleTextAttribute(handle, 3);

	/* The first step: Find the modulus of all elements of the array */
	for (int index = 0; index < countOfSave; index++)
	{
		if (arr[index] == 0)
			arr[index] = 0;

		if (arr[index] < 0)
			arr[index] = arr[index] + -2 * arr[index];
	}

	/* The second step: Find the minimum modul element of the array */
	int minimumModul = arr[0];

	for (int index = 1; index < countOfSave; index++)
	{
		if ((minimumModul > arr[index]))
		{
			minimumModul = arr[index];
		}
	}

	/* Output the minimum modul element */
	std::cout << minimumModul << std::endl;
	SetConsoleTextAttribute(handle, 7);

	/* <----------------------------------------------------------------------------> */
	
	/* The second condition in the task */
	std::cout << std::endl;
	std::cout << "2) The sum of the moduls of the array's elements which standing after the first zero element: ";
	
	/* Find the sum of the modules of the array elements located after
	   the first element, which is equal to zero. */
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

	/* Output the sum of the modules of the array */
	SetConsoleTextAttribute(handle, 3);
	std::cout << sumModul << std::endl;
	SetConsoleTextAttribute(handle, 7);

	/* <----------------------------------------------------------------------------> */

	/* Special condition in the task after the first and the second condition */
	std::cout << std::endl;
	std::cout << "The first half of the array contains elements that are in pair position, " << std::endl;
	std::cout << "the second half of the array contains elements that are in odd position: ";

	SetConsoleTextAttribute(handle, 3);

	/* The first half of the array in which wrote the elements which standing in pair positions */
	for (int index = 0; index < countOfSave; index++)
		if (index % 2 == 0)
			std::cout << arr[index] << " ";

	/* The second half of the array in which wrote the elements which standing in odd positions */
	for (int index = 0; index < countOfSave; index++)
		if (index % 2 == 1)
			std::cout << arr[index] << " ";

	SetConsoleTextAttribute(handle, 7);

	std::cout << std::endl;

	/* <----------------------------------------------------------------------------> */

	return 0;
}