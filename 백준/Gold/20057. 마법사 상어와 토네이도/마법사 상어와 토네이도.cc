#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

// 20 20 5 a(55)


int board[505][505];
bool vis[505][505];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int dr[4][10] = {
	{ 0, -1, 0, 1,   -2,   -1, 0, 1, 0,  -1}, 
	{ -2, -1,-1,-1,   0,   1, 1, 1, 2,   0},
	{ 0, 1, 0, -1,   2,   1, 0, -1, 0,   1},
	{ -2, -1,-1,-1,   0,   1, 1, 1, 2,   0},
};
int dc[4][10] = {
	{ 2, 1, 1, 1,   0,   -1, -1, -1, -2,  0},
	{ 0, -1, 0, 1,   -2,   -1, 0, 1, 0,  -1} ,
	{ -2, -1,-1,-1,   0,   1, 1, 1, 2,   0},
	{ 0, 1, 0, -1,   2,   1, 0, -1, 0,   1 }
};
int sand[9] = { 2, 10, 7, 1,   5,   10, 7, 1, 2 };
int sum, ans;
int n, d;

void chk(int r, int c, int a) {
	sum += a;
	if (r < 0 || r >= n || c < 0 || c >= n) {
		ans += a;
		return;
	}
	board[r][c] += a;
}

void f(int x, int y) { // d 위0 왼1 아래2 오른쪽3
	if (x == 0 && y == 0) return;
	vis[x][y] = true;

	int tmp = (d + 1) % 4;
	if (!vis[x + dx[tmp]][y + dy[tmp]]) d = tmp;

	x += dx[d];
	y += dy[d];

	sum = 0;
	int cur = board[x][y];

	for (int i = 0; i < 9; i++) {
		chk(x + dr[d][i], y + dc[d][i], cur * sand[i] / 100);
	}
	chk(x + dr[d][9], y + dc[d][9], cur - sum);

	cur = 0;
	f(x, y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	f(n / 2, n / 2);

	cout << ans;
}