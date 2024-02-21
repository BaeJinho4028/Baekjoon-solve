#include <bits/stdc++.h>
using namespace std;

int p[55];

int f(int x) {
	if (p[x] == -1) return x;
	return p[x] = f(p[x]);
}

bool dif(int u, int v) {
	u = f(u); v = f(v);
	if (u == v) return false;
	p[u] = v;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0, m =0;
	tuple<int, int, int> e[2505];
	memset(p, -1, sizeof(p));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '0') continue;

			int tmp;
			if ('a' <= c && c <= 'z') tmp = c - 'a' + 1;
			else tmp = c - 'A' + 27;
			sum += tmp;
			e[m++] = { tmp, i, j };
		}
	}
	sort(e, e + m);

	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		tie(c, a, b) = e[i];
		if (!dif(a, b)) continue;
		ans += c;
		cnt++;
	}

	if (cnt == n - 1) cout << sum - ans;
	else cout << -1;
}