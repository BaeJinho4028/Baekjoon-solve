#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[55][55];
bool chk[55][55];
int tmp[55];
int n, m, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;

		for (int i = x; i <= n; i += x) {
			if (d == 0) {
				for (int j = 0; j < m; j++) {
					int idx = (j + k) % m;
					tmp[idx] = board[i][j];
				}
			}
			else {
				for (int j = 0; j < m; j++) {
					int idx = (j + k) % m;
					tmp[j] = board[i][idx];
				}
			}

			for (int j = 0; j < m; j++)
				board[i][j] = tmp[j];
		}

		bool same = false;
		memset(chk, false, sizeof(chk));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) continue;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx<1 || nx > n) continue;
					if (ny == -1) ny = m - 1;
					if (ny == m) ny = 0;

					if (board[i][j] == board[nx][ny]) {
						same = true;
						chk[nx][ny] = true;
					}
				}
			}
		}

		if (same) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (chk[i][j]) board[i][j] = 0;
				}
			}
		}
		else {
			int sum = 0, cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (board[i][j] != 0) {
						sum += board[i][j];
						cnt++;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (board[i][j] != 0) {
						if (board[i][j] * cnt > sum) board[i][j] -= 1;
						else if (board[i][j] * cnt < sum) board[i][j] += 1;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			ans += board[i][j];
		}
	}
	cout << ans;
}