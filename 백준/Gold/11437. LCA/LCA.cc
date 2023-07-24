#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[50005];
bool vis[50005];
int p[50005], d[50005];

void dfs(int cur, int dep) {
	vis[cur] = true;
	d[cur] = dep;

	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;

		p[nxt] = cur;
		dfs(nxt, dep + 1);
	}
}

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);

	while (d[a] != d[b]) a = p[a];

	while (a != b) {
		a = p[a];
		b = p[b];
	}

	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	cin >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}