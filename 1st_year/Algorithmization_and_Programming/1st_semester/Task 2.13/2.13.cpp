#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float a, b, c; int D;
	
	cout << "Введите коэффициенты a, b, c" << endl;
	cin >> a >> b >> c;

	D = b * b - 4 * a * c;
	
	if (D > 0)
	{
		cout << "Первый корень равен:" << ((b * (-1) + sqrt(D)) / (2 * a)) << endl;
		cout << "Второй корень равен:" << ((b * (-1) - sqrt(D)) / (2 * a)) << endl;
	}
	else if (D == 0)
	{
		cout << "Корень равен:" << (b * (-1)) / (2 * a) << endl;
	}
	else
	{
		cout << "Корней нет" << endl;
	}
}
