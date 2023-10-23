#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
bool vis[505];
int ans;

void dfs() {
	stack<int> s;
	s.push(1);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		vis[cur] = 1;

		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = 1;
			ans++;
			if (cur == 1) s.push(nxt);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();
	cout << ans;
}