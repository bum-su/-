#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> arr;

	int count = 0;
	while (n) {
		int temp = 0;
		temp = n % 10;
		arr.push_back(temp);
		n /= 10;
		count++;
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	for (int i = 0; i < count; i++) {
		cout << arr[i];
	}
	cout << "\n";
}