#include<iostream>
using namespace std;

int n, m;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void solve(int number, int depth) 
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
    }
	for(int i = number; i <= n; i++)
	{
		arr[depth] = i;
		solve(number, depth + 1);
		number++;
	}
}


int main()
{
	cin >> n >> m;
	solve(1, 0);
}