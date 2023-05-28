#include <bits/stdc++.h>
using namespace std;

int board[20][20];
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 }; //가로 세로 대각선
int n, ans;

void dfs(int x, int y, int chk) { //x,y, 방향 가로 세로 대각선
	if (x == n && y == n) {
		ans++;
		return;
	}

	for (int dir = 0; dir < 3; dir++) {
		if ((dir == 0 && chk == 1) || (dir == 1 && chk == 0)) continue;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <1 || nx > n || ny <1 || ny >n) continue;
		if (board[nx][ny] == 1) continue;
		if (dir == 2 && (board[nx][y] == 1 || board[x][ny] == 1)) continue;
		dfs(nx, ny, dir);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(1, 2, 0);
	cout << ans;
}