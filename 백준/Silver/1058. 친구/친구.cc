#include <bits/stdc++.h>
using namespace std;

int cnt, mx;
vector<int> adj[55];
int n;
bool vis[55];

void dfs(int x, int cur) {
	vis[x] = true;
	if (cur == 2) return;

	for (auto nxt : adj[x]) {
		dfs(nxt, cur + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == 'Y') adj[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		memset(vis, false, sizeof(vis));
		dfs(i, 0);

		for (int j = 1; j <= n; j++) {
			if (vis[j]) cnt++;
		}

		mx = max(mx, cnt - 1);
	}

	cout << mx;
}