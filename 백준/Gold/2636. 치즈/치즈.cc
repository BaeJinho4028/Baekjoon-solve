#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[105][105];
bool vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int tmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;
	for (int time = 0;; time++) {
		vis[0][0] = true;
		q.push({ 0, 0 });
		int cnt = 0;
		memset(vis, false, sizeof(vis));

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
				if (vis[nx][ny]) continue;

				vis[nx][ny] = true;
				if (board[nx][ny] == 0)
					q.push({ nx, ny });
				if (board[nx][ny] == 1) {
					cnt++;
					board[nx][ny] = 0;
				}
			}
		}

		if (cnt == 0) {
			cout << time << '\n' << tmp;
			break;
		}
		tmp = cnt;
	}
}