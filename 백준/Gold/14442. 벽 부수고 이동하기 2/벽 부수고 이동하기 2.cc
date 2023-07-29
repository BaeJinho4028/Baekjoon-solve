#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m, k;
char board[1005][1005];
int dist[1005][1005][12];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	
	queue<tuple<int, int, int>> q;
	dist[1][1][0] = 1;
	q.push({ 1,1,0 });

	while (!q.empty()) {
		auto [x, y, z] = q.front(); q.pop();;

		if (x == n && y == m) {
			cout << dist[x][y][z];
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > n || ny < 1 || ny >m) continue;

			if (board[nx][ny] == '1' && dist[nx][ny][z + 1] == -1 && z < k) {
				q.push({ nx,ny,z + 1 });
				dist[nx][ny][z + 1] = dist[x][y][z] + 1;
			}
			if (board[nx][ny] == '0' && dist[nx][ny][z] == -1) {
				q.push({ nx,ny,z });
				dist[nx][ny][z] = dist[x][y][z] + 1;
			}
		}
	}

	cout << -1;
}