#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 1505;
char board[MX][MX];
bool vis[MX][MX], chk[MX][MX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int lx, ly, cnt;
bool flag;

queue<pair<int, int>> q, nq, lq, nlq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				lx = i;
				ly = j;
			}
			if (board[i][j] != 'X') q.push({ i, j });
		}
	}

	lq.push({ lx, ly });
	board[lx][ly] = '.';
	vis[lx][ly] = true;

	while (!flag) {
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			chk[cur.X][cur.Y] = true;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (chk[nx][ny]) continue;

				if (board[nx][ny] == 'X') nq.push({ nx,ny });
				chk[nx][ny] = true;
			}
		}

		while (!nq.empty()) {
			auto cur = nq.front(); nq.pop();
			board[cur.X][cur.Y] = '.';
			q.push({ cur.X, cur.Y });
		}
		cnt++;

		while (!lq.empty()) {
			auto cur = lq.front(); lq.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (vis[nx][ny]) continue;

				if (board[nx][ny] == 'X') {
					vis[nx][ny] = 1;
					nlq.push({ nx,ny });
					continue;
				}
				else if (board[nx][ny] == 'L') {
					flag = true;
					break;
				}

				lq.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}

		while (!nlq.empty()) {
			auto cur = nlq.front(); nlq.pop();
			lq.push({ cur.X, cur.Y });
		}
	}
	cout << cnt;
}