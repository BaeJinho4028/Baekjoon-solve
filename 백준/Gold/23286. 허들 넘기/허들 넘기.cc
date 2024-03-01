#include <bits/stdc++.h>
using namespace std;

int adj[305][305];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			adj[i][j] = '????';
		}
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a][b] = min(adj[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
			}
		}
	}

	while (t--) {
		int a, b;
		cin >> a >> b;
		if (adj[a][b] == '????') cout << -1 << '\n';
		else cout << adj[a][b] << '\n';
	}
}