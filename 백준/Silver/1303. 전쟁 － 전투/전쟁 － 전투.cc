#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[105][105];
bool vis[105][105];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int w, b;

int bfs(int x, int y) {
	vis[x][y] = true;
	queue<pair<int, int>> q;

	q.push({ x, y });

	int cnt = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[cur.X][cur.Y] != board[nx][ny]) continue;
			if (vis[nx][ny]) continue;
			q.push({ nx, ny });
			vis[nx][ny] = true;
			cnt++;
		}
	}

	return cnt;
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
			int tmp = bfs(i, j);
			if (board[i][j] == 'W') w += tmp * tmp;
			else b += tmp * tmp;
		}
	}

	cout << w << ' ' << b;
}