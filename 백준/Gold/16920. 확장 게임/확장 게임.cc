#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, p;
int s[15], ans[15];
queue<pair<int,int>> q[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= '0' && board[i][j] <= '9') {
				int num = board[i][j] - '0';
				q[num].push({ i, j });
			}
		}
	}
	while (1) {
		bool flag = true;
		for (int t = 1; t <= p; t++) {
			int chk = s[t];
			while (!q[t].empty() && chk--) {
				int size = q[t].size();
				for (int i = 0; i < size; i++) {
					auto cur = q[t].front(); q[t].pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != '.') continue;
						flag = false;
						q[t].push({ nx,ny });
						board[nx][ny] = t + '0';
					}
				}
			}
		}
		if (flag) break;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[board[i][j] - '0']++;
		}
	}

	for (int i = 1; i <= p; i++) {
		cout << ans[i] << ' ';
	}
}