#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "1 0" << "\n";
	}
	else{
		for (int i = 0; i < n; i++)
		{
			int T, start = 1, start_temp = 1, result = 0;
			cin >> T;

			for (int j = 0; j < T; j++)
			{
				start = start_temp;
				start_temp = result;
				result = start + start_temp;
			}
			cout << start_temp << " " << result << "\n";
		}
	}
}