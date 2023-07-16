#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int deg[32005];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		deg[v]++;
	}

	queue<int> q;
	vector<int> r;

	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		r.push_back(cur);
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (auto x : r) cout << x << ' ';
}