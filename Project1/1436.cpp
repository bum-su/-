#include <iostream>
using namespace std;

int solve(int n) {
	int result = 666, test;

	while (n) {
		test = result;
		while (test) {
			int mod = 0;
			mod = test % 1000;
			test /= 10;
			if (mod == 666) {
				n--;
				break;
			}
		}
		result++;
	}
	return result-1;
}

int main() {
	int n;
	cin >> n;
	cout << solve(n);
}