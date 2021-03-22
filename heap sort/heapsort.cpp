#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// left child is greater than root
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	// right child is greater than root
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n)
{
	//build the heap
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << "\n" << arr[i];
}


int main()
{
	int arr[] = { 12, 11 ,13 ,5 ,6 ,7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The array is \n";
	printArray(arr, n);

	heapsort(arr, n);
	cout << "The sorted array is \n";
	printArray(arr, n);
}