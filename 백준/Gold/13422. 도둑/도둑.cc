#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 0, sum = 0;
		int st = 0, en = m - 1;
		for (int i = 0; i < m; i++) {
			sum += a[i];
		}

		if (n == m) {
			cout << (sum < k ? 1 : 0) << '\n';
			continue;
		}
		while (1) {
			if (sum < k) ans++;
			sum -= a[st];
			st++;
			en++;
			if (en == n) en = 0;
			if (en == m - 1) break;
			sum += a[en];
		}
		cout << ans << '\n';
	}
}