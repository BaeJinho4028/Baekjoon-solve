#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[55][55];
int dist[55][55];
int n, m, mx;
int dx[8] = { 1, 1, 1, 0 , 0, -1, -1, -1 };
int dy[8] = { 1, 0 , -1, 1, -1, 1, 0, -1 };

int main() { //앞부분을 잘라내며 팰린드롬이면 잘라낸만큼 더하면 팰린드롬됨
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	queue<pair<int, int>> q;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mx = max(mx, dist[i][j]);
		}
	}

	cout << mx;
}