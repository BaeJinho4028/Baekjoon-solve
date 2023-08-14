#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[105][105];
int dist[105][105];
int n, m, t;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;

	int a, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) a = i, b = j;
		}
	}

	memset(dist, '????', sizeof(dist));
	queue<pair<int, int>> q;

	q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] != '????') continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	int tmp = min(dist[n - 1][m - 1], dist[a][b] + (abs((n - 1) - a)) + abs((m - 1) - b));
	if (t >= tmp) cout << tmp;
	else cout << "Fail";
}