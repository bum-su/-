#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, sum = 0, max = 0, temp, mode;
	bool isSecond = false;
	cin >> n;
	vector<int> arr(n);
	vector<int> arr2(8001, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		temp = (arr[i] <= 0) ? abs(arr[i]) : arr[i] + 4000;
		arr2[temp]++;
		if (arr2[temp] > max)
			max = arr2[temp];
	}
	sort(arr.begin(), arr.end());

	for (int i = -4000; i < 4001; i++) {
		temp = i <= 0 ? abs(i) : i + 4000;
		if (arr2[temp] == max) {
			mode = i;
			if (isSecond)
				break;
			isSecond = true;
		}
	}
	cout << round(sum / (double) n) << '\n';
	cout << arr[round(n/2)] << '\n';
	cout << mode << '\n';
	cout << arr[n - 1] - arr[0] << "\n";
}