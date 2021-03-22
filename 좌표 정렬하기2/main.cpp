#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	pair<int, int> arr[100000];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i].second << " " << arr[i].first << "\n";
	}
}