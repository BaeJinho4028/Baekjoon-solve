#include <bits/stdc++.h>
using namespace std;

int n;
int t[505], d[505];
vector<int> adj[505];
int deg[505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		int u;
		while (cin >> u) {
			if (u == -1) break;

			adj[u].push_back(i);
			deg[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
			d[i] = t[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			d[nxt] = max(d[nxt], d[cur] + t[nxt]);
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << d[i] << '\n';
	}
}