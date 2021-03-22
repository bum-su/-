#include<iostream>
using namespace std;

int n;
int arr[11];
int operators[4];
int Min = 1000000001;
int Max = -1000000001;

void solve(int result, int ind)
{
	if (ind == n)
	{
		if (result > Max)
			Max = result;
		if (result < Min)
			Min = result;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			if (i == 0)
				solve(result + arr[ind], ind + 1);
			else if (i == 1)
				solve(result - arr[ind], ind + 1);
			else if (i == 2)
				solve(result * arr[ind], ind + 1);
			else
				solve(result / arr[ind], ind + 1);
			operators[i]++;
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}

	solve(arr[0], 1);

	cout << Max << "\n" << Min;
}