#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	float n1, n2; float sum = 0;
	float* ptr1; float* ptr2;

	std::cout << "������� ��� �����: " << std::endl;
	std::cin >> n1 >> n2;

	ptr1 = &n1;
	ptr2 = &n2;
	
	sum = *ptr1 + *ptr2;

	std::cout << "����� �����: " << std::endl;
	std::cin >> sum;
}