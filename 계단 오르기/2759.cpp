#include<iostream>
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

	int n;
	cin >> n;
	int *arr = new int[n], *dp = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = MAX(arr[0] + arr[1], arr[1]);
	dp[2] = MAX(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < n; i++)
		dp[i] = MAX(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
	cout << dp[n - 1] << endl;
}