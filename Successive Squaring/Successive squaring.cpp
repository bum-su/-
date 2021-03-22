#include<iostream>

using namespace std;

int tenConverTwo(int n)
{
	int result = 0;

	for (int i = 1; n > 0; i *= 10)
	{
		int binary = n % 2;
		result += binary * i;
		n /= 2;
	}
	return result;
}

int Successive_Squaring(int n)
{
	return n;
}

int main()
{
	int t = tenConverTwo(7);

	cout << t;
}