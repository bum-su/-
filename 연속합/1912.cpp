#include<iostream>
#define endl "\n"
using namespace std;

long long MAX(long long a, long long b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	long long max;
	cin >> n;
	int *arr = new int[n];
	long long *dp = new long long[n];
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	max = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = MAX(arr[i], dp[i - 1] + arr[i]);
		max = MAX(max, dp[i]);
	}
	cout << max << endl;
}