#include <iostream>

// 아래는 랜덤 피봇을 사용하기 위해 필요한 패키지
// #include <cstdlib>
// #include <ctime>
using namespace std;
//퀵정렬
int n, quick[10000001];

int MAX(int a, int b, int c)
{
	return a > b && a > c ? a : b > c ? b : c;
}

int MIN(int a, int b, int c)
{
	return a < b && a < c ? a : b < c ? b : c;
}

// 중간 값 pivot을 구하기 위한 함수
int mid(int a, int b, int c)
{
	int midean = (quick[a] + quick[b] + quick[c]) - MAX(quick[a], quick[b], quick[c]) - MIN(quick[a], quick[b], quick[c]);

	return midean == quick[a] ? a : midean == quick[b] ? b : c;
}

void quickSort(int i, int j)
{
	if (i >= j) return;

	// int pivot = quick[(rand()%(j-i+1))+i]; << 랜덤 피봇;

	int pivot = quick[mid(i, j, (i + j) / 2)]; //중간값 피봇
	int left = i;
	int right = j;

	while (left <= right)
	{
		while (quick[left] < pivot) left++;
		while (quick[right] > pivot) right--;
		if (left <= right)
		{
			int temp = 0;
			temp = quick[left];
			quick[left] = quick[right];
			quick[right] = temp;
			left++; right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// srand((unsigned int)time(NULL));	time seed값

	cin >> n;
	for (int i = 0; i < n; i++) cin >> quick[i];

	quickSort(0, n - 1);

	for (int j = 0; j < n; j++) cout << quick[j] << "\n";
}