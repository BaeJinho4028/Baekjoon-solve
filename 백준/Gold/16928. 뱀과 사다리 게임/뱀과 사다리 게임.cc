#include <bits/stdc++.h>
using namespace std;

int adj[105];
int dist[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (n--) {
		int u, v;
		cin >> u >> v;
		adj[u] = v;
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u] = v;
	}

	memset(dist, -1, sizeof(dist));

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int nx = cur + i;
			if (nx > 100) continue;
			if (adj[nx] != 0) nx = adj[nx];
			if (dist[nx] == -1) {
				dist[nx] = dist[cur] + 1;
				q.push(nx);
			}
		}
	}
	cout << dist[100];
}
