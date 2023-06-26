#include <bits/stdc++.h>
using namespace std;

vector<int> adj[205];
bool vis[205];

void dfs(int x) {
	vis[x] = true;

	for (auto nxt : adj[x])
		if(!vis[nxt])dfs(nxt);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int x, cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (x == 1) adj[i].push_back(j);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x;
		if (vis[x]) continue;
		cnt++;
		dfs(x);
	}

	if (cnt == 1) cout << "YES";
	else cout << "NO";
}