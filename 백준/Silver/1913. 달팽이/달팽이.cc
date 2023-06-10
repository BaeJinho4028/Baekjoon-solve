#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int x = 1, y = 1, dir = 0;
	int ax, ay;
	for (int i = n * n; i > 0; i--) {
		board[x][y] = i;
		
		if (i == k) ax = x, ay = y;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <1 || nx >n || ny <1 || ny >n || board[nx][ny] != 0) dir = (dir + 1) % 4;
		
		x = x + dx[dir];
		y = y + dy[dir];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << ax << ' ' << ay;
}