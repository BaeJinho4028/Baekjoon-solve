#include <bits/stdc++.h>
using namespace std;

vector<int> p(100005, -1);

int f(int x) {
	if (p[x] == -1) return x;
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

	int n, m;
	cin >> n >> m;

	long long sum = 0;
	vector<tuple<int, int, int>> e;

	for(int i=0; i<m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		sum += c;
		e.push_back({ c, u, v });
	}
	sort(e.begin(), e.end());

	long long tmp = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		int c, a, b;
		tie(c, a, b) = e[i];
		if (!dif(a, b)) continue;
		tmp += c;
		cnt++;
	}
	if (cnt == n - 1) cout << sum - tmp;
	else cout << -1;
}