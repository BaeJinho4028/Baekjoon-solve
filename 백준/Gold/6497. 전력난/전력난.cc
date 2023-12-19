#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<tuple<int, int, int>> e;
int p[200005];

int f(int x) {
	if (p[x] < 0) return x;
	return p[x] = f(p[x]);
}

bool dif(int u, int v) {
	u = f(u); v = f(v);
	if (u == v) return 0;
	p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;

		int sum = 0;
		fill(p, p+n, -1);
		e.clear();

		int u, v, c;
		while (m--) {
			cin >> u >> v >> c;
			e.push_back({ c, u, v });
			sum += c;
		}

		sort(e.begin(), e.end());

		int cnt = 0, ans = 0;
		for (int i = 0; i < e.size(); i++) {
			int u, v, c;
			tie(c, u, v) = e[i];
			if (!dif(u, v)) continue;

			ans += c;
			cnt++;
			if (cnt == n - 1) break;
		}

		cout << sum - ans << '\n';
	}

	return 0;
}