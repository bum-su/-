#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, max = 0;
	cin >> n;
	int *dp = new int [n];
	vector <pair<int, int>> arr;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a, b });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i].second > arr[j].second)
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
		max = MAX(max, dp[i]);
	}
	cout << n - max << endl;
}