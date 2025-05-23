#include <iostream>

using namespace std;

int board[8][8];

const int Queen = -1;

void resetBoard();
void showBoard();
bool checkQueen(int i);
void setQueen(int i, int j);

void resetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
}

void showBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == Queen)
			{
				cout << "Q ";
			}
			else
			{
				cout << ". ";
			}
		}
		cout << endl;
	}
}

void setQueen(int i, int j)
{
	for (int x = 0; x < 8; ++x)
	{
		board[x][j] += 1;				//óêàçûâàåì íà àòàêó ïî âåðòèêàëè
		board[i][x] += 1;				//óêàçûâàåì íà àòàêó ïî ãîðèçîíàòèë
		
		int d;
		d = j - i + x;					//âû÷èñëÿåì äèàãîíàëü
		if (d >= 0 && d < 8)
		{
			board[x][d] += 1;
		}

		d = j + i - x;
		if (d >= 0 && d < 8)
		{
			board[x][d] += 1;
		}
	}
	board[i][j] = Queen;
}

void deleteQueen(int i, int j)
{
	for (int x = 0; x < 8; ++x)
	{
		board[x][j] -= 1;				//óêàçûâàåì íà àòàêó ïî âåðòèêàëè
		board[i][x] -= 1;				//óêàçûâàåì íà àòàêó ïî ãîðèçîíàòèë

		int d;
		d = j - i + x;					//âû÷èñëÿåì äèàãîíàëü 1
		if (d >= 0 && d < 8)
		{
			board[x][d] -= 1;
		}

		d = j + i - x;					//âû÷èñëÿåì äèàãîíàëü 2
		if (d >= 0 && d < 8)
		{
			board[x][d] -= 1;
		}
	}
	board[i][j] = 0;
}

bool checkQueen(int i)
{
	bool result = false;

	for (int j = 0; j < 8; ++j)
	{
		if (board[i][j] == 0)
		{
			setQueen(i, j);

			if (i == 7)
			{
				result = true;
			}
			else if (!(result = checkQueen(i + 1)))
			{
				deleteQueen(i, j);
			}
		}
		if (result)
		{
			break;
		}
	}
	return result;
}

int main()
{
	resetBoard();
	checkQueen(0);
	showBoard();
	return 0;
}
