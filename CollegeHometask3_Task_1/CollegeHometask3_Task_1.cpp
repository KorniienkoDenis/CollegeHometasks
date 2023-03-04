#include <iostream>

/*

	Завдання 1. UKRAINIAN VERSION COMMENT.
	===============================================================
	Напишіть програму для розрахунку по вказаних формулах. Провести
	модульне та інтеграційне тестування створеного алгоритму.

	Варіант 10.

	z1 = (sin(pi/2 + 3alpha)) / 1 - sin(3alpha - pi);
	z2 = ctg((5/4pi) + (3/2alpha));
	===============================================================

	---------------------------------------------------------------

	Task 1. ENGLISH VERSION COMMENT.
	====================================================================
	Write a program for calculation according to the indicated formulas.
	Conduct module and integration testing of the created algorithm.

	Variant 10.

	z1 = (sin(pi/2 + 3alpha)) / (1 - sin(3alpha - pi));
	z2 = ctg((5 / 4) * pi + (3 / 2) * alpha));
	====================================================================

*/

double Cotan(const double& pi, double& alpha)
{
	return 1 / (tan((5 * pi) / 4 + (3 * alpha) / 2));
}

int main()
{
	const double pi = 3.14f;

	double alpha;
	double resultFirstFormula;
	double resultSecondFormula;

	std::cout << "input alpha: ";
	std::cin >> alpha;
	std::cout << std::endl;

	resultFirstFormula = (sin(pi / 2 + 3 * alpha)) / (1 - sin(3 * alpha - pi));
	std::cout << "z1 = (sin(pi" << " / 2 + 3 * " << alpha << ")) / (1 - sin(3 * " << alpha << " - pi))\n";
	std::cout << "The result of the first formula: " << resultFirstFormula;
	
	std::cout << std::endl;
	std::cout << std::endl;

	resultSecondFormula = Cotan(pi, alpha);
	std::cout << "z2 = ctg((5 / 4) * pi + (3 / 2) * " << alpha << ")\n";
	std::cout << "The result of the second formula: " << resultSecondFormula;
	std::cout << std::endl;

	return 0;
}