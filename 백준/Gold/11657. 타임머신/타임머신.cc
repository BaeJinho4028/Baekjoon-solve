#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define INF 0x7f7f7f7f

vector<pair<int, int>> edge[505];
long long dist[505];
bool cycle;

int main() { //벨만포드 맛보기 : 음수 사이클
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
	}

	fill(dist, dist + n + 1, INF);

	dist[1] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				int nx = edge[i][j].X;
				int nc = edge[i][j].Y;

				if (dist[i] != INF && dist[nx] > dist[i] + nc) {
					dist[nx] = dist[i] + nc;
					if (k == n) cycle = true;
				}
			}
		}
	}

	if (cycle)cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
}