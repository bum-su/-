#include<iostream>
using namespace std;

int main()
{
	int arr[10] = { 10, 9, 5, 1, 9, 3, 6, 4, 7, 8 };
	int temp[11] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		temp[arr[i]]++;
	}

	for (int i = 1; i < 11; i++)
	{
		for (int j = 0; j < temp[i]; j++)
		{
			cout << i << " ";
		}
	}

	return 0;
}