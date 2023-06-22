#include <bits/stdc++.h>
using namespace std;

int ans, mx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a, b;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x > 0) a.push_back(x);
		else b.push_back(-x);

		mx = max(mx, abs(x));
	}

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());

	while (!a.empty()) {
		ans += a[0] * 2;
		for (int i = 0; i < m; i++) {
			if (a.empty()) break;
			a.erase(a.begin());
		}
	}

	while (!b.empty()) {
		ans += b[0] * 2;
		for (int i = 0; i < m; i++) {
			if (b.empty()) break;
			b.erase(b.begin());
		}
	}

	cout << ans - mx;
}