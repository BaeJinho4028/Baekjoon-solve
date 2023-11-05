#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

char board[10][10];
int d[10][10][2];
int n;
int mx = -'????', mn = '????';
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };


void bt(int x, int y, int c) {
	if (x == n && y == n) {
		mn = min(mn, c);
		mx = max(mx, c);
		return;
	}

	for (int dir = 0; dir < 2; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		int nc = c;

		if (nx > n || ny > n) continue;

		if (board[x][y] == '+')
			nc += (board[nx][ny] - '0');
		if (board[x][y] == '-')
			nc -= (board[nx][ny] - '0');
		if (board[x][y] == '*')
			nc *= (board[nx][ny] - '0');
		
		bt(nx, ny, nc);
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

	bt(1, 1, board[1][1] - '0');
	cout << mx << ' ' << mn;
}