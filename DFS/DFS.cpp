#include<iostream>
#include<vector>
using namespace std;

vector<int> v[9];
int arr[9];

void DFS(int start)
{
	if (arr[start]) return;

	arr[start] = true;
	cout << start << " ";

	for (int i = 0; i < v[start].size(); i++)
	{
		DFS(v[start][i]);
	}
}

int main()
{
	v[0].push_back(1);
	v[1].push_back(0);

	v[1].push_back(2);
	v[2].push_back(1);

	v[1].push_back(3);
	v[3].push_back(1);

	v[2].push_back(3);
	v[3].push_back(2);

	v[2].push_back(4);
	v[4].push_back(2);

	v[2].push_back(5);
	v[5].push_back(2);

	v[3].push_back(6);
	v[6].push_back(3);

	v[4].push_back(5);
	v[5].push_back(4);

	v[4].push_back(7);
	v[7].push_back(4);

	v[3].push_back(8);
	v[8].push_back(3);

	DFS(0);

	return 0;
}