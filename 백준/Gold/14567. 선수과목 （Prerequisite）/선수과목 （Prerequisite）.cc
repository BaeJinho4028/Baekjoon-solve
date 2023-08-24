#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003

int n, m;
int deg[1005];
vector<int> adj[1005];
int ans[1005];

int main() {
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

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
		ans[i] = 1;
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) {
				q.push(nxt);
				ans[nxt] = max(ans[nxt], ans[cur] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}