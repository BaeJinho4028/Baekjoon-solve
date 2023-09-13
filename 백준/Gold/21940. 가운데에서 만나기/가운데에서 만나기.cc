#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int d[205][205];
int c[205];

const int MX = 987987987;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, MX);
		d[i][i] = 0;
	}

	while (m--) {
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = t;
	}

	cin >> k;
	for (int i = 1; i <= k; i++) cin >> c[i];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= k; j++) //i도시일때 친구의 왕복시간 중 최대
			tmp = max(tmp, d[i][c[j]] + d[c[j]][i]);
		v.push_back({ tmp, i });
	}
	sort(v.begin(), v.end());

	int mn = v[0].first;
	for (auto cur : v) {
		if (mn < cur.first) break;
		cout << cur.second << ' ';
	}
}