#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    begin:

    int n;
    char star = '*'; char space = ' ';

    cout << "¬ведите натуральное нечетное число N, большее 3" << endl;
    cin >> n;

    int nstar = 1; int nspace = (n - nstar) / 2;; int k = (n + 1) / 2;

    if ((n <= 3) or (n % 2 != 1))
    {
        cout << "Ѕыло введено неверное N" << endl;
        goto begin;
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= nspace; j++)
            {
                cout << space;
            }
            for (int j = 1; j <= nstar; j++)
            {
                cout << star;
            }
            for (int j = 1; j <= nspace; j++)
            {
                if (j = nspace)
                {
                    cout << space << endl;
                }
                else
                {
                    cout << space;
                }
            }
            nspace = nspace - 1;
            nstar = nstar + 2;
        }   
    }
}
    