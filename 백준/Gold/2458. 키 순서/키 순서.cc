#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
const int INF = 1000000000;

int n, m;
int dist[505][505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = '????';
			if (i == j) dist[i][j] = 0;
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != '????' || dist[j][i] != '????') {
				cnt++;
			}
		}
		if (cnt == n) ans++;
	}
	cout << ans;
}