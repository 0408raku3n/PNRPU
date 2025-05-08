#include <iostream>
#include <cmath>

using namespace std;

int main()
{
float n, a, max;
int i = 2;
int count = 1;

cin >> n;

max = sin(n + 1/n);

while (i <= n)
{
    a = sin(n + 1/n);
    if (a > max)
    {
        max = a;
        count = 1;
    }
    else if (a == max)
    {
        count++;
    }
    i++;
}
cout << "Максимальный элемент: " << max << " Его номер: " << num << endl;
}
