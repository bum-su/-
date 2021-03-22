#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long arr[100] = { 1, 1, 1, 2, 2 };

	for (int j = 5; j < 100; j++)
	{
		arr[j] = arr[j - 1] + arr[j - 5];
	}

	while (T--)
	{
		int n;
		cin >> n;
		cout << arr[n - 1] << "\n";
	}
}