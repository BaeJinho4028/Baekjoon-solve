#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
bool vis[10005];
vector<int> ans;
int mx;

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	vis[idx] = true;
	int cnt = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
			cnt++;
		}
	}

	if (mx < cnt) {
		ans.clear();
		mx = cnt;
		ans.push_back(idx);
	}
	else if (mx == cnt)
		ans.push_back(idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, false);
		bfs(i);
	}

	for (int a : ans)
		cout << a << ' ';
}