#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<int> adj[100005];
int n, m, r;
int dist[100005];

void dfs(int x) {
	if (dist[x]) return;

	dist[x] = ++cnt;
	for (auto nxt : adj[x]) {
		dfs(nxt);
	}
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
		sort(adj[i].begin(), adj[i].end(), greater<>());

	dfs(r);

	for (int i = 1; i <= n; i++)
		cout << dist[i] << '\n';
}