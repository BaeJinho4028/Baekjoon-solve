#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[10005];
bool vis[10005];
int ans, en; // 길이, 끝점좌표

void dfs(int x, int l) {
	if (vis[x]) return;

	vis[x] = true;

	if (ans < l) {
		ans = l;
		en = x;
	}

	for (auto a : adj[x]) {
		dfs(a.first, l + a.second);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	dfs(1, 0);

	ans = 0;
	memset(vis, false, sizeof(vis));

	dfs(en, 0);
	cout << ans;
}