#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300005];
int dist[300005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	queue<int> q;
	fill(dist, dist + n + 1, 0x7f7f7f7f7f);
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			if (dist[nxt] > dist[cur] + 1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			cout << i << '\n';
			flag = true;
		}
	}
	if (!flag) cout << -1;
}