#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[55][55];
int dist[55][55];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	memset(dist, '????', sizeof(dist));

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == '1') {
				if (dist[nx][ny] > dist[cur.X][cur.Y]) {
					dist[nx][ny] = dist[cur.X][cur.Y];
					q.push({ nx, ny });
				}
			}
			else {
				if (dist[nx][ny] > dist[cur.X][cur.Y] + 1) {
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << dist[n - 1][n - 1];
}