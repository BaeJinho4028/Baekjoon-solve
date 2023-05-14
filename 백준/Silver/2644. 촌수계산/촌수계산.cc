#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int dist[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int n, m, x, y;
	cin >> n;
	cin >> x >> y;
	cin >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	fill(dist, dist + 105, -1);
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	cout << dist[y];
}