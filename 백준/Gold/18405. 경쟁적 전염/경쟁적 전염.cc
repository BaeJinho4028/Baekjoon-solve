#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[205][205];
int dist[205][205]; //time
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;
	memset(dist, 500000, sizeof(dist));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] != 0 && board[nx][ny] <= board[cur.X][cur.Y]) continue;
			if (dist[nx][ny] >= dist[cur.X][cur.Y] + 1) {
				q.push({ nx, ny });
				board[nx][ny] = board[cur.X][cur.Y];
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
	}

	/*
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	if (dist[x-1][y-1] <= s) cout << board[x-1][y-1];
	else cout << 0;

}