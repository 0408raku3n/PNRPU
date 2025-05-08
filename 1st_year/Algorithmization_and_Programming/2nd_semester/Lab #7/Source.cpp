#include <iostream>
#include <complex>

using namespace std;

int product(int a, int b);
complex<double> product(complex<double> a, complex<double> b);

int main()
{
	setlocale(LC_ALL, "Russian");

	int num1, num2;

	cout << "Ââåäèòå ïåðâîå öåëîå ÷èñëî: " << endl;
	cin >> num1;
	cout << "Ââåäèòå âòîðîå öåëîå ÷èñëî: " << endl;
	cin >> num2;

	cout << "Ïðîèçâåäåíèå öåëûõ ÷èñåë ðàâíî: " << endl;
	cout << product(num1, num2) << endl;

	double real1, imag1, real2, imag2;

	cout << "Ââåäèòå äåéñòâèòåëüíóþ ÷àñòü ïåðâîãî êîìïëåêñíîãî ÷èñëà: " << endl;
	cin >> real1;
	cout << "Ââåäèòå ìíèìóþ ÷àñòü ïåðâîãî êîìïëåêñíîãî ÷èñëà: " << endl;
	cin >> imag1;

	cout << "Ââåäèòå äåéñòâèòåëüíóþ ÷àñòü âòîðîãî êîìïëåêñíîãî ÷èñëà: " << endl;
	cin >> real2;
	cout << "Ââåäèòå ìíèìóþ ÷àñòü âòîðîãî êîìïëåêñíîãî ÷èñëà: " << endl;
	cin >> imag2;

	complex<double> comp_num1(real1, imag1);
	complex<double> comp_num2(real2, imag2);

	cout << "Ïðîèçâåäåíèå êîìïëåêñíûõ ÷èñåë ðàâíî: " << endl;
	cout << real(product(comp_num1, comp_num2)) << " + " << imag(product(comp_num1, comp_num2)) << "i";
}

int product(int a, int b)
{
	return a * b;
}
complex<double> product(complex<double> a, complex<double> b)
{
	return a * b;
}
