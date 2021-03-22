#include <iostream>
using namespace std;

int DP[501][501];

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main() {

	int i, j;
	int n, max = -1;

	cin >> n;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cin >> DP[i][j];
		}
	}

	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (j == 1) DP[i][j] += DP[i - 1][j];
			else if (j == i) DP[i][j] += DP[i - 1][j - 1];
			else DP[i][j] += MAX(DP[i - 1][j - 1], DP[i - 1][j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		max = MAX(max, DP[n][i]);
	}

	cout << max << "\n";

	return 0;
}