#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
char board[1005][1005];
int dist[1005][1005][2];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int ans = -1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	dist[0][0][0] = dist[0][0][1] = 1;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int x, y, b;
		tie(x, y, b) = q.front();
		if (x == n - 1 && y == m - 1) {
			ans = dist[x][y][b];
			break;
		}
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (x < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0' && dist[nx][ny][b] == -1) {
				dist[nx][ny][b] = dist[x][y][b] + 1;
				q.push({ nx,ny,b });
			}
			if (!b && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = dist[x][y][b] + 1;
				q.push({ nx,ny,1 });
			}
		}
	}

	cout << ans;
}