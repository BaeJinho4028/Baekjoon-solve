#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
	for (int i = 2; i <= 64; i++) {
		int tmp = n;
		string s;

		while (tmp) {
			s.push_back(tmp % i);
			tmp /= i;
		}

		string r;

		for (int j = s.size() - 1; j >= 0; j--)
			r += s[j];

		if (s == r)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << solve(n) << '\n';
	}
}