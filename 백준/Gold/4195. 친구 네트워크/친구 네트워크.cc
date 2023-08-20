#include <bits/stdc++.h>
using namespace std;

int p[200005];
int cnt[200005]; //연결된 수

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

int merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		p[v] = u;
		cnt[u] += cnt[v];
		cnt[v] = 1;
	}

	return cnt[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i <= 200000; i++) {
			cnt[i] = 1;
			p[i] = i;
		}

		map<string, int> ma;

		int node = 1;

		while (n--) {
			string a, b;
			cin >> a >> b;

			if (ma.count(a) == 0) ma[a] = node++;
			if (ma.count(b) == 0) ma[b] = node++;

			cout << merge(ma[a], ma[b]) << '\n';
		}
	}
}