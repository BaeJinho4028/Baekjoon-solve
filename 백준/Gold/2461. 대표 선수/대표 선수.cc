#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<int> idx;

	for (int i = 0; i < n; i++) {
		idx.push_back(0);
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		sort(a[i], a[i]+m);

	int ans = '????';
	while (1) {
		int mx = -1, mn = '????';
		int mn_i = 0;

		for (int i = 0; i < n; i++) {
			if (mn > a[i][idx[i]]) {
				mn = a[i][idx[i]];
				mn_i = i;
			}
			mx = max(mx, a[i][idx[i]]);
		}

		ans = min(ans, mx - mn);
		idx[mn_i]++;
		if (idx[mn_i] == m) break;
;	}

	cout << ans;
}