#include <bits/stdc++.h>
using namespace std;

char board[55][55];
int dist[55][55];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

void dfs(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (board[x][y] != board[nx][ny]) continue;
		if (dist[x][y] - dist[nx][ny] >= 3) {
			cout << "Yes";
			exit(0);
		}
		if (dist[nx][ny] != '????') continue;

		dist[nx][ny] = dist[x][y] + 1;
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

	memset(dist, '????', sizeof(dist));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] != '????') continue;
			dist[i][j] = 0;
			dfs(i, j);
		}
	}

	cout << "No";
}