#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n, m, r;
int board[305][305];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void rotate(int st, int mod) {
	int c = r % mod;

	for (int i = 0; i < c; i++) {
		int tmp = board[st][st];
		int x = st, y = st;

		int dir = 0;
		while (dir < 4) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx == st && ny == st) break;

			if (nx < st || nx >= n - st || ny < st || ny >= m - st) {
				dir++;
				continue;
			}

			board[x][y] = board[nx][ny];
			x = nx;
			y = ny;
		}
		board[st + 1][st] = tmp;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = min(n, m) / 2;

	int a = n, b = m;

	for (int i = 0; i < cnt; i++) {
		rotate(i, 2 * a + 2 * b - 4); //박스 한바퀴 주기
		a -= 2;
		b -= 2; //가로세로 2씩 줄어듬
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
