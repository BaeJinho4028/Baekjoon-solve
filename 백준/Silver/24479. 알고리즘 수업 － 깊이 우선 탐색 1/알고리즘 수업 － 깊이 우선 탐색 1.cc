#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int n, m, r;
int dist[100005];
int cnt;

void dfs(int cur) {
	if (dist[cur] != 0) return;
	dist[cur] = ++cnt;

	for (auto nxt : adj[cur])
		dfs(nxt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	dfs(r);

	for (int i = 1; i <= n; i++)
		cout << dist[i] << '\n';
}