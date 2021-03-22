#include <iostream>

using namespace std;
int dp[1000001];

int MIN(int a, int b)
{
	return a > b ? b : a;
}

int solution(int n)
{
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = MIN(dp[i / 2] + 1, dp[i]);
		if (i % 3 == 0)
			dp[i] = MIN(dp[i / 3] + 1, dp[i]);
	}

	return dp[n];
}
int main()
{
	dp[1] = 0;
	int n;
	cin >> n;

	cout << solution(n);
}