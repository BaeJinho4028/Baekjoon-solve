#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m;
int board[55][55];
bool vis[55][55];
int dx[4] = { 0,-1,0,1 }; //서북동남
int dy[4] = { -1,0,1,0 };
int cnt, mx, ans;

int bfs(int x, int y) {
	int chk = 0;

	queue<pair<int, int>> q;
	vis[x][y] = true;
	q.push({ x,y });
	chk++;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		int wall = 1;

		for (int dir = 0; dir < 4; dir++, wall *= 2) {
			if ((board[cur.X][cur.Y] & wall) != wall) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[nx][ny]) continue;

				vis[nx][ny] = true;
				q.push({ nx,ny });
				chk++;
			}
		}
	}

	return chk;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			cnt++;
			mx = max(mx, bfs(i, j));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int wall = 1; wall <= 8; wall *= 2) {
				if ((board[i][j] & wall) == wall) {
					memset(vis, false, sizeof(vis));
					board[i][j] -= wall;
					ans = max(ans, bfs(i, j));
					board[i][j] += wall;
				}
			}
		}
	}

	cout << cnt << '\n' << mx << '\n' << ans;
}