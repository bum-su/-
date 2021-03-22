#include<iostream>
#include<vector>
using namespace std;

vector <int> a[3];

int main()
{

	a[0].push_back(1);
	a[0].push_back(2);
	a[0].push_back(3);

	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(1);
	a[2].push_back(2);
	a[2].push_back(3);


	for (int i = 0; i < a[0].size(); i++)
	{
		cout << a[2][i] << " ";
	}

	return 0;
}