#include <bits/stdc++.h>
using namespace std;

long long d[205][205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, x, y;
	cin >> w >> h >> x >> y;

	d[1][1] = 1;

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			d[i][j] += (d[i - 1][j] + d[i][j - 1]) % 1000007;
		}
	}

	int tmp = d[y][x];
	memset(d, 0, sizeof(d));
	d[y][x] = 1;


	if (!(x == w && y == h)) {
		for (int i = y; i <= h; i++) {
			for (int j = x; j <= w; j++) {
				d[i][j] += (d[i - 1][j] + d[i][j - 1]) % 1000007;
			}
		}
	}

	cout << (tmp * d[h][w]) % 1000007;
}