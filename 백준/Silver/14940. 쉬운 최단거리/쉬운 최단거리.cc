#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int n, m;
int board[1005][1005];
int dist[1005][1005];
int a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}


	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;
			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1 && board[i][j] == 0) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}