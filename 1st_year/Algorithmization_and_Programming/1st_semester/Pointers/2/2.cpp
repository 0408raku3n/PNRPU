#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n1, n2; int sum = 0;
	int* ptr1; int* ptr2;

	std::cout << "¬ведите два числа: " << std::endl;
	std::cin >> n1 >> n2;

	ptr1 = &n1;
	ptr2 = &n2;
	
	sum = *ptr1 + *ptr2;

	std::cout << "—умма равна: " << std::endl;
	std::cin >> sum;
}