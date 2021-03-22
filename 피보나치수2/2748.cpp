#include<iostream>

using namespace std;

int main()
{
	int n;
	long long start = 1, temp = 1, result = 0;

	cin >> n;

	if (n == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			start = temp;
			temp = result;
			result = start + temp;
		}
		cout << result;
	}
}