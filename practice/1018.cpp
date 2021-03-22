#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[50][50] , board1[8][8], board2[8][8], result;
int temp1, temp2;

void sol(int i, int j) {
	temp1 = temp2 = 0;
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if (arr[i + a][j + b] != board1[a][b]) temp1++;
			if (arr[i + a][j + b] != board2[a][b]) temp2++;
		}
	}
	result = min(result, temp1);
	result = min(result, temp2);
}

int main()
{
	int n, m;
	result = 64;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'B') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) {
		board1[x][y] = (x + y + 1) % 2;
		board2[x][y] = (x + y) % 2;
	}
	for (int i = 0; i + 8 <= n; i++) {
		for (int j = 0; j + 8 <= m; j++) {
			sol(i, j);
		}
	}
	cout << result << endl;
}

