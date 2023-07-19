#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[20][20];
int tmp[20][20];
bool vis[20][20];
bool die[20][20];
int dx[3] = { 0,-1,0 };
int dy[3] = { -1,0,1 };
int n, m, d;
int ans;

void bfs(int a, int b, int c) {
	int cnt = 0;
	int ac[3] = { a,b,c };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = board[i][j];
			die[i][j] = false;
		}
	}

	int idx = n;

	while (idx > 0) {
		for (int i = 0; i < 3; i++) { //궁수
			memset(vis, false, sizeof(vis));

			queue<pair<int, int>> q;
			int x = idx - 1; //한칸 앞
			int y = ac[i];
			
			q.push({ x, y });
			vis[x][y] = true;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				if (tmp[cur.X][cur.Y] == 1) {
					die[cur.X][cur.Y] = true;
					break;
				}

				for (int dir = 0; dir < 3; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny]) continue;

					if (abs(idx - nx) + abs(ac[i] - ny) <= d) {
						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (die[i][j]) tmp[i][j] = 0;
			}
		}
		idx--; //궁수가 이동하는 방식
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (die[i][j]) cnt++;
		}
	}
	ans = max(ans, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				bfs(i, j, k);
			}
		}
	}

	cout << ans;
}