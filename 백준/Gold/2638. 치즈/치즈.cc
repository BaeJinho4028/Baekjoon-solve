#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m;
int board[105][105];
int dist[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;

	int t;
	for (t = 0; ; t++) {

		memset(dist, 0, sizeof(dist));
		q.push({ 0,0 });
		dist[0][0] = 1;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 0) {
					if (dist[nx][ny] > 0) continue;
					dist[nx][ny]++;
					q.push({ nx,ny });
				}
				else {
					dist[nx][ny]++;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) cnt++;
				if (dist[i][j] >= 2) {
					board[i][j] = 0;
				}
			}
		}
		if (cnt == 0) break;

	}

	cout << t;
}
