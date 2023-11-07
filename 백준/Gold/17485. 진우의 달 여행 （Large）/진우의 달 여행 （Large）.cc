#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int board[1005][1005];
int d[1005][1005][3];
int dx[4] = { 0,-1,0,1 };
int n, m;

int f(int r, int c, int dir) {
	if (c < 1 || c > m) return '????';
	if (r == n) return board[r][c];

	int& ret = d[r][c][dir];
	if (ret != '????') return ret;

	for (int i = 1; i <= 3; i++) {
		if (i == dir) continue;
		ret = min(ret, f(r+1, c + dx[i], i) + board[r][c]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	
	memset(d, '????', sizeof(d));

	int ans = '????';
	for (int i = 1; i <= m; i++) ans = min(ans, f(0, i, 0));
	
	cout << ans;
}