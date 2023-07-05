#include <bits/stdc++.h>
using namespace std;

int n, k;
int t[1005], d[1005], ans[1005];
vector<int> adj[100005];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n >> k;

		memset(t, 0, sizeof(t));
		memset(d, 0, sizeof(d));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 1001; i++) adj[i].clear();

		for (int i = 1; i <= n; i++)
			cin >> t[i];

		while (k--) {
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
			d[v]++;
		}

		int w;
		cin >> w;

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				q.push(i);
				ans[i] = t[i];
			}
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto nxt : adj[cur]) {
				ans[nxt] = max(ans[nxt], ans[cur] + t[nxt]);
				d[nxt]--;
				if (d[nxt] == 0) q.push(nxt);
			}
		}

		cout << ans[w] << '\n';
	}
}