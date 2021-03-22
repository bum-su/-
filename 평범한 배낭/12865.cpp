#include <iostream>
using namespace std;

int n, k;
int d[100001] = { 0, };  // ���� �뷮
int w[101];     // ������ ����
int v[101];     // ������ ��ġ

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) 
	{
		for (int j = k; j >= 1; j--) 
		{
			if (w[i] <= j)
				d[j] = MAX(d[j], d[j - w[i]] + v[i]);
		}
	}

	cout << d[k] << "\n";
}