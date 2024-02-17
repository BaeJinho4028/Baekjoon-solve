#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[105];
int deg[105];
int chk[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int x, y, k;
		cin >> x >> y >> k;
		adj[y].push_back({ x, k });
		deg[x]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
			chk[i][i] = 1;
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (auto nxt : adj[cur]) {
			for (int i = 1; i <= n; i++) {
				chk[nxt.X][i] += chk[cur][i] * nxt.Y;
			}

			if (--deg[nxt.X] == 0) {
				q.push(nxt.X);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (chk[n][i] == 0) continue;
		cout << i << ' ' << chk[n][i] << '\n';
	}
}