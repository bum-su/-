#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, tmp;
	cin >> n;
	vector<int> a;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
}