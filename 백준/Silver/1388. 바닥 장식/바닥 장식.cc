#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[55][55];
bool vis[55][55];
int ans;
int dx[2] = { 1, -1 };

void dfs(int x, int y) {
	vis[x][y] = true;

	for (int dir = 0; dir < 2; dir++) {
		int nx = x;
		int ny = y;
		if (board[x][y] == '-') {
			ny += dx[dir];
		}
		else {
			nx += dx[dir];
		}

		if (nx < 0 || nx >= n || ny <0 || ny >=m) continue;
		if (vis[nx][ny] || board[x][y] != board[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			dfs(i, j);
			ans++;
		}
	}
	cout << ans;
}