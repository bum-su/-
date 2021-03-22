#include<iostream>
using namespace std;

int n, cnt = 0;
int board[15];

bool check(int level)
{
	for (int i = 0; i < level; i++) 
	{
		if (board[i] == board[level] || abs(board[level] - board[i]) == level - i)
			return false;
	}
	return true;
}

void n_queen(int x) 
{
	if (x == n)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			board[x] = i;
			if (check(x))
				n_queen(x + 1);
		}
	}
}

int main() 
{
	cin >> n;
	n_queen(0);
	cout << cnt << endl;
}