#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[5][5][5];
int tmp[5][5][5];
int ans[5][5][5];
int dist[5][5][5];
int mn = '????';

int dh[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,0,-1,0 };
int dy[6] = { 0,0,0,1,0,-1 };

bool chk[5];
int cnt;

int bfs() {
	if (ans[0][0][0] == 0) return '????';

	queue<tuple<int, int, int>> q;
	memset(dist, '????', sizeof(dist));
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int h, x, y;
		tie(h, x, y) = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nh = h + dh[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nh < 0 || nh >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (ans[nh][nx][ny] != 1) continue;
			if (dist[nh][nx][ny] > dist[h][x][y] + 1) {
				dist[nh][nx][ny] = dist[h][x][y] + 1;
				q.push({ nh, nx, ny });
			}
		}
	}

	return dist[4][4][4];
}

void rotate(int h, int num) {
	
	if (num == 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[h][i][j] = board[h][i][j];
			}
		}
	}

	if (num == 1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[h][i][j] = board[h][5-j-1][i];
			}
		}
	}

	if (num == 2) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[h][i][j] = board[h][5-i-1][5-j-1];
			}
		}
	}

	if (num == 3) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp[h][i][j] = board[h][j][5-i-1];
			}
		}
	}
}


void st(int cur) {
	if (cur == 5) {
		mn = min(mn, bfs());
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				ans[cur][j][k] = tmp[i][j][k];
			}
		}
		st(cur + 1);
		chk[i] = false;
	}
}


void bt(int cur) {
	if (cur == 5) {
		st(0);
		return;
	}

	for (int i = 0; i < 4; i++) {
		rotate(cur, i);
		bt(cur + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> board[i][j][k];
			}
		}
	}

	bt(0);

	if (mn == '????') mn = -1;
	cout << mn;
}