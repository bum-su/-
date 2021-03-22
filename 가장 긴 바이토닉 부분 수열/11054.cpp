#include<iostream>
#define endl "\n"
using namespace std;

int MAX(int a, int b)
{
	return b > a ? b : a;
}

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int n, max = 1, max_2 = 1;
	cin >> n;
	int *arr = new int[n], *dp = new int[n], *dp2 = new int[n];


	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
	}

	for (int i = n - 1; i > -1; i--)
	{
		dp2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
				dp2[i] = MAX(dp2[i], dp2[j] + 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		max = MAX(max, dp[i] + dp2[i] - 1);
	}
	cout << max << endl;
}