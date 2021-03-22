#include <iostream>
using namespace std;

int TenconverTwo(int num)
{
	int i = 1;
	int result = 0;

	while (num > 0)
	{
		result += (num % 2) * i;
		i *= 10;
		num /= 2;
	}

	return result;
}

int TwoConverTen(int num)
{
	int result = 0;
	int mul = 1;
	while (num > 0)
	{
		if (num % 2)
		{
			result += mul;
		}
		mul *= 2;
		num /= 10;
	}

	return result;
}

int main()
{
	cout << TenconverTwo(12) << "\n";
	cout << TwoConverTen(1110);
}
