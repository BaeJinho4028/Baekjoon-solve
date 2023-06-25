#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[55][55];
int dist[55][55];
int water[55][55];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
int ansx, ansy;
queue<pair<int, int>> q, w;//비버, 물

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'D') {
				ansx = i;
				ansy = j;
			}
			if (board[i][j] == 'S') {
				q.push({ i, j });
				dist[i][j] = 0;
			}
			if (board[i][j] == '*')
				w.push({ i, j });
		}
	}

	while (!q.empty()) {
		int ws = w.size();

		for (int i = 0; i < ws; i++) { //큐만큼 돌려야함 주의!
			auto tmp = w.front(); w.pop();

			for (int dir = 0; dir < 4; dir++) { //물 이동
				int nx = tmp.X + dx[dir];
				int ny = tmp.Y + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (board[nx][ny] != '.') continue;
				board[nx][ny] = '*';
				w.push({ nx, ny });
			}
		}

		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			auto cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) { //고슴도치 이동
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (board[nx][ny] == 'D') {
					cout << dist[cur.X][cur.Y] + 1;
					exit(0);
				}
				if (board[nx][ny] != '.') continue;
				if (dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	cout << "KAKTUS";
}