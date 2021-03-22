#include<iostream>
#define endl "\n"
#include<string>
using namespace std;

int _atoi(char* a)
{
	int n;
	
	if (*a >= 0x30 && *a <= 0x39)
	{
		n = *a - 0x30;
	}
	return n;
}

int MAX(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr_1[10004], arr_2[10004], max, result[10004], carry = 0;
	string a, b;
	cin >> a >> b;

	max = MAX(a.length(), b.length());

	for (int i = 0; i < a.length(); i++)
	{
		arr_1[a.length() - i] = _atoi(&a.at(i));
	}

	for (int i = 0; i < b.length(); i++)
	{
		arr_2[b.length() - i] = _atoi(&b.at(i));
	}

	for (int i = 1; i <= max; i++)
	{
		result[i] = arr_1[i] + arr_2[i] + carry;
		if (result[i] > 9)
		{
			result[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	if (carry) cout << 1;

	for (int i = 0; i < max; i++)
		cout << result[max - i];

	return 0;
}