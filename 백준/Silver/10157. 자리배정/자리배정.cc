#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int board[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int x = 0, y = 1, dir = 0;
	board[x][y] = 1;

	for (int i = 1; i <= n * m; i++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (board[nx][ny] != 0 || nx < 1 || nx > m || ny < 1 || ny > n)
			dir = (dir + 1) % 4;
		board[x + dx[dir]][y + dy[dir]] = i;
		x = x + dx[dir];
		y = y + dy[dir];

		
		if (i == k) {
			cout << y << ' ' << x;
			return 0;
		}
	}

	cout << '0';
}