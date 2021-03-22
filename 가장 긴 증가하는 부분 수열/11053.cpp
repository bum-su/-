#include<iostream>
#define endl "\n"
using namespace std;

int MAX(int a, int b)
{
	return b > a ? b : a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, cnt = 0 , max = 0;
	cin >> n;
	int *arr = new int[n], *dp = new int[n];

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
		max = MAX(max, dp[i]);
	}
	cout << max << endl;
}