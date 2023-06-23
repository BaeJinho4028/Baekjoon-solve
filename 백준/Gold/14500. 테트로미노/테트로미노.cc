#include <bits/stdc++.h>
using namespace std;

int board[505][505];
bool vis[505][505];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, ans;

void solve(int x, int y, int cur, int num) {
	if (cur == 4) {
		ans = max(ans, num);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (vis[nx][ny]) continue;

		vis[nx][ny] = 1;
		solve(nx, ny, cur + 1, num + board[nx][ny]);
		vis[nx][ny] = 0;
	}

	// ㅏ ㅓ ㅗ ㅜ 모양은 따로 처리 x y 는 중심
	if (!(x - 1 < 0 || x + 1 >= n || y < 0 || y + 1 >= m)) // ㅏ
		ans = max(ans, (board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y + 1]));
	if (!(x - 1 < 0 || x + 1 >= n || y - 1 < 0 || y >= m)) // ㅓ
		ans = max(ans, (board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y - 1]));
	if (!(x - 1 < 0 || x >= n || y - 1 < 0 || y + 1 >= m)) // ㅗ
		ans = max(ans, (board[x][y] + board[x][y - 1] + board[x - 1][y] + board[x][y + 1]));
	if (!(x < 0 || x + 1 >= n || y - 1 < 0 || y + 1 >= m)) // ㅜ
		ans = max(ans, (board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1]));
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = true;
			solve(i, j, 1, board[i][j]);
			vis[i][j] = false;
		}
	}

	cout << ans;
}