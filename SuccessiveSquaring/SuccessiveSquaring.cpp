#include<iostream>
#include<string>

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

int Successive_Squaring(int a, int m, int n)
{
	int new_n = tenConverTwo(n);
	string s_n = to_string(new_n);

	/*int num = 1;
	int count = 0;

	while (s_n[count])
	{
		num = pow(num, 2);

		if (s_n[count] - 49 == 0)
		{
			num *= a;
        }
		
		num %= m;

		count++;
	}

	return num;*/

	int result = 1;
	
	for (int i = 0; i < s_n.size(); i++)
	{
		result = pow(result, 2);
		result = result * (s_n[i] - 49 == 0 ? a : 1);

		result %= m;
	}

	return result;
}

int main()
{
	cout << Successive_Squaring(7, 701, 283);
}