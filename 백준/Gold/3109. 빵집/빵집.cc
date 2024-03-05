#include <bits/stdc++.h>
using namespace std;

int r, c;
char board[10005][505];
int cnt;
int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };

bool dfs(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c) return false;
	if (board[x][y] != '.') return false;

	board[x][y] = 'x';

	if (y == c-1) {
		cnt++;
		return true;
	}

	for (int dir = 0; dir < 3; dir++) {
		if (dfs(x+dx[dir], y+dy[dir])) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	for (int k = 0; k < r; k++) {
		dfs(k, 0);
	}
	cout << cnt;
}