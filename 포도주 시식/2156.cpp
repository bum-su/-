#include<iostream>
using namespace std;

int MAX(int a, int b, int c)
{
	return a > b ? (a > c) ? a : c : (b > c) ? b : c;
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n + 1], *dp = new int[n + 1];

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = MAX(dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]);
	}

	cout << dp[n] << endl;
}