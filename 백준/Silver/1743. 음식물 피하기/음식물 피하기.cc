#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int mx, cnt;
int board[105][105];
bool vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	queue<pair<int, int>> q;

	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 0) continue;

			q.push({ i, j });
			vis[i][j] = 1;
			cnt = 1;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
					cnt++;
				}
			}

			mx = max(mx, cnt);
		}
	}

	cout << mx;
}