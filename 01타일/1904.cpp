#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<long long> answer = { 0, 1, 2 };
	cin >> n;

	if (n < 3)
		cout << answer[n];
	else
	{
		for (int i = 3; i <= n; i++)
		{
			answer.push_back((answer[i - 2] + answer[i - 1]) % 15746);
		}
		cout << answer[n] % 15746;
	}
}