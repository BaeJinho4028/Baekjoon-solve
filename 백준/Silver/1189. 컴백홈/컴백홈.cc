#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[10][10];
bool vis[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans;
int r, c, k;

void dfs(int cur, int x, int y) {
	if (cur == k - 1) {
		if (x == 0 && y == c - 1)
			ans++;
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (board[nx][ny] == 'T' || vis[nx][ny]) continue;
		vis[nx][ny] = true;
		dfs(cur + 1, nx, ny);
		vis[nx][ny] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	vis[r - 1][0] = true;
	dfs(0, r - 1, 0);

	cout << ans;
}