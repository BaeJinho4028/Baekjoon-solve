#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
vector<pair<int, int>> adj[100005];
bool vis[100005];
int mx;

bool bfs(int c) {
	queue<int> q;
	q.push(a);
	vis[a] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == b) return true;

		for (auto nxt : adj[cur]) {
			int nx = nxt.first;
			int nc = nxt.second;

			if (vis[nx] || c > nc) continue;
			vis[nx] = true;
			q.push(nx);
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;

		adj[u].push_back({ v, c });
		adj[v].push_back({ u, c });

		mx = max(mx, c);
	}
	cin >> a >> b;

	int st = 0, en = mx;
	while (st <= en) {
		memset(vis, false, sizeof(vis));
		int mid = (st + en) / 2;
		if (bfs(mid)) st = mid + 1;
		else en = mid - 1;
	}

	cout << en;
}