#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int board[305][305];
int d[305][305];

int f(int x, int y) {
	if (x < 1 || y < 1) return 0;

	int& ret = d[x][y];
	if (~ret) return d[x][y];

	ret = max(f(x - 1, y), f(x, y - 1)) + board[x][y];

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << f(n, m);
}