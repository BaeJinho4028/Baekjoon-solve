#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[10][10], tmp[10][10];
bool vis[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, mx;

void bfs() {
	queue<pair<int, int>> q;
	memset(vis, false, sizeof(vis));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = board[i][j];
			if (tmp[i][j] == 2) {
				q.push({ i, j });
				vis[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || tmp[nx][ny] != 0) continue;
			q.push({ nx, ny });
			vis[nx][ny] = true;
			tmp[nx][ny] = 2;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) cnt++;
		}
	}

	mx = max(mx, cnt);
	return;
}

void solve(int cur) {
	if (cur == 3) return bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0) continue;
			board[i][j] = 1;
			solve(cur + 1);
			board[i][j] = 0;
		}
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

	solve(0);

	cout << mx;
}