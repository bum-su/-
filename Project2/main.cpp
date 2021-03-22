#include<iostream>

using namespace std;

int arr[] = { 10, 5, 30, 9, 1, 2, 8, 3 };
int n = sizeof(arr) / sizeof(arr[0]);
int *arr_2 = new int[n];

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int arr_i = left;
	int arr_j = mid + 1;

	int arr2_i = left;

	while (arr_i <= mid && arr_j <= right)
	{
		if (arr[arr_i] <= arr[arr_j])
			arr_2[arr2_i++] = arr[arr_i++];
		else
			arr_2[arr2_i++] = arr[arr_j++];
	}

	int tmp = arr_i > mid ? arr_j : arr_i;

	while (tmp <= right) arr_2[arr2_i++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = arr_2[i];
}

void partition(int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main(void)
{
	partition(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}