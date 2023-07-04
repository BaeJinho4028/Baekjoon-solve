#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int board[505][505], d[505][505];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dfs(int x, int y){
	if (x == n - 1 && y == m - 1) return 1;
	if (d[x][y] != -1) return d[x][y];

	d[x][y] = 0;
	for (int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] >= board[x][y]) continue;
			d[x][y] += dfs(nx, ny);
	}
	return d[x][y];
}

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			d[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
}