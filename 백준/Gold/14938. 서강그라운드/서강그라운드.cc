#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int item[105];
int d[105][105];
int nxt[105][105];
bool vis[105];
int ans, tmp;

void visit(int i, int j) {
	int cur = i;
	while (cur != j) {
		vis[cur] = 1;
		cur = nxt[cur][j];
	}
	vis[j] = 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		int sc; cin >> sc;
		item[i] = sc;
	}

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, 987987987);
		d[i][i] = 0;
	}

	int x, y, dist;
	while (r--) {
		cin >> x >> y >> dist;
		d[x][y] = dist; d[y][x] = dist;
		nxt[x][y] = y; nxt[y][x] = x;
	}

	for(int k= 1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}

	for (int i = 1; i <= n; i++) {
		tmp = 0;
		for (int j = 1; j <= n; j++)
			vis[j] = 0;

		for (int j = 1; j <= n; j++) {
			if (d[i][j] > m) continue;
			visit(i, j);
		}
		for (int j = 1; j <= n; j++)
			if (vis[j]) tmp += item[j];
		ans = max(ans, tmp);
	}
	cout << ans;
}