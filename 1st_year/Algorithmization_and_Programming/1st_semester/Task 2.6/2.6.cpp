#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    begin:

    int n;
    char star = '*'; char space = ' ';

    cout << "¬ведите натуральное число N, большее 2" << endl;
    cin >> n;

    int nstar = n; int nspace = 0;

    if (n <= 2) 
    {
        cout << "Ѕыло введено неверное N" << endl;
        goto begin;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= nspace; j++)
            {
                cout << space;
            }
            for (int j = 1; j <= nstar; j++)
            {
                cout << star;
            }
            cout << endl;
            nspace = nspace + 1;
            nstar = nstar - 1;
        }   
    }
}
    