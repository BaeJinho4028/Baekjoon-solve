#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int cnt;
vector<int> adj[100005];
int dist[100005];

void bfs(int x) {
	queue<int> q;

	dist[x] = ++cnt;
	q.push(x);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt]) continue;
			q.push(nxt);
			dist[nxt] = ++cnt;
		}
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

	bfs(r);

	for (int i = 1; i <= n; i++)
		cout << dist[i] << '\n';
}