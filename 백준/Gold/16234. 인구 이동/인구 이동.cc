#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[55][55];
bool vis[55][55];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, l, r, sum, cnt;
bool flag = true;
queue<pair<int, int>> q;
vector<pair<int, int>> v;

void bfs(int x, int y) {
	q.push({ x, y });
	vis[x][y] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny]) continue;

			int tmp = abs(board[nx][ny] - board[cur.X][cur.Y]);
			if (tmp >= l && tmp <= r) {
				q.push({ nx, ny });
				vis[nx][ny] = true;

				v.push_back({ nx, ny });
				sum += board[nx][ny];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	while (flag) {
		flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vis[i][j]) {
					v.clear();
					v.push_back({ i, j });
					sum = board[i][j];
					bfs( i, j );
				}

				if (v.size() >= 2) {
					flag = true;
					for (int k = 0; k < v.size(); k++) {
						board[v[k].X][v[k].Y] = sum / v.size();
					}
				}
			}
		}

		if (flag) cnt++;
	}

	cout << cnt;
}