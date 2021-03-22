#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool compair(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, string>> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	stable_sort(vec.begin(), vec.end(), compair);

	for (int i = 0; i < n; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
}