
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define Z third
int board[102][102][102];
int dist[102][102][102];
int n, m, h;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int>> q;

int main() {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					q.push({i,j,k });
				if (board[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curX, curY, curZ;
		tie(curZ, curY, curX) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (dist[nz][ny][nx] >= 0) continue;
			dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
			q.push({ nz, ny, nx });
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
}