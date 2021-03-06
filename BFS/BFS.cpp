#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> a[7];
bool c[7];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!c[y])
			{
				q.push(y);
				c[y] = true;
			}
		}
	}
}


int main()
{
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(4);
	a[2].push_back(5);

	a[3].push_back(1);
	a[3].push_back(6);

	a[4].push_back(2);

	a[5].push_back(2);

	a[6].push_back(3);

	bfs(1);

	return 0;
}