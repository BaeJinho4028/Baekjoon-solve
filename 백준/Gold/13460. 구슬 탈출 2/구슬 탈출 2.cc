#include <bits/stdc++.h>
using namespace std;

struct marble {
	int rx, ry;
	int bx, by;
	int cnt;
};

int n, m;
char board[15][15];
bool vis[15][15][15][15];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void move(int& nx, int& ny, int& dist, int& dir) {
	while (board[nx + dx[dir]][ny + dy[dir]] != '#' && board[nx][ny] != 'O') {
		nx += dx[dir];
		ny += dy[dir];
		dist++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int RX, RY, BX, BY;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') RX = i, RY = j;
			if (board[i][j] == 'B') BX = i, BY = j;
		}
	}

	queue<marble> q;
	q.push({ RX, RY, BX, BY, 0 });
	vis[RX][RY][BX][BY] = true;
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) break;

		for (int dir = 0; dir < 4; dir++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncnt = cnt + 1;

			move(nrx, nry, rc, dir);
			move(nbx, nby, bc, dir);

			if (board[nbx][nby] == 'O') continue;
			if (board[nrx][nry] == 'O') {
				cout << ncnt;
				return 0;
			}

			if (nrx == nbx && nry == nby) {
				if (rc > bc) nrx -= dx[dir], nry -= dy[dir];
				else nbx -= dx[dir], nby -= dy[dir];
			}

			if (vis[nrx][nry][nbx][nby]) continue;
			vis[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, ncnt });
		}
	}

	cout << -1;
}