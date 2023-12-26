#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char board[25][25];
int ans = '????';

bool out(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

void dfs(int cur, int x1, int y1, int x2, int y2) {
	if (cur == 10)
		return;

	for (int dir = 0; dir < 4; dir++) {
		int nx1 = x1 + dx[dir];
		int ny1 = y1 + dy[dir];
		int nx2 = x2 + dx[dir];
		int ny2 = y2 + dy[dir];
		if (out(nx1, ny1) && out(nx2, ny2)) continue;
		else if (!out(nx1, ny1) && !out(nx2, ny2)) {
			if (board[nx1][ny1] == '#' && board[nx2][ny2] == '#')
				continue;
			else if (board[nx1][ny1] == '#')
				dfs(cur + 1, x1, y1, nx2, ny2);
			else if (board[nx2][ny2] == '#')
				dfs(cur + 1, nx1, ny1, x2, y2);
			else
				dfs(cur + 1, nx1, ny1, nx2, ny2);
		}
		else {
			ans = min(ans, cur + 1);
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				if (x1 == -1 && y1 == -1)
					x1 = i, y1 = j;
				else
					x2 = i, y2 = j;
			}
		}
	}

	dfs(0, x1, y1, x2, y2);

	if (ans == '????') cout << -1;
	else cout << ans;
}