#include <iostream>>
#include <string.h>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char text[255] = {};
	int endWord;
	int startWord;

	cout << "Введите текст (закончите ввод точкой): \n";
	cin.getline(text, 255);

	for (int i = 1; i < 255; i++)
	{
		if (text[i] == ' ' || text[i] == '.')
		{
			int k = i - 1;

			endWord = k;
			
			while (text[k] != ' ' && k != 0)
			{
				k--;
			}

			if (k == 0)
			{
				startWord = k;
			}
			else
			{
				startWord = k + 1;
			}
			

			bool flag = true;
			for (int j = startWord; j <= endWord; j++)
			{
				if (text[j] == 'а' || text[j] == 'у' || text[j] == 'о' || text[j] == 'е' || text[j] == 'и' || text[j] == 'я' || text[j] == 'ю' || text[j] == 'ё' || text[j] == 'э' || text[j] == 'ы' || text[j] == 'А' || text[j] == 'У' || text[j] == 'О' || text[j] == 'Е' || text[j] == 'И' || text[j] == 'Я' || text[j] == 'Ю' || text[j] == 'Ё' || text[j] == 'Э' || text[j] == 'Ы')
				{
					flag = false;
				}
			}
			
			if (flag)
			{
				for (int j = startWord; j <= endWord; j++)
				{
					cout << text[j];
				}
				cout << endl;
			}
		}	
	}
}
