#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		vector<int> tmp;
		tmp.push_back(n);
		tmp.push_back(i);
		for (int j = 1;; j++) {
			if (tmp[j - 1] - tmp[j] < 0) break;
			tmp.push_back(tmp[j - 1] - tmp[j]);
		}

		if (tmp.size() > v.size()) v = tmp;
	}

	cout << v.size() << '\n';
	for (int a : v) cout << a << ' ';
}