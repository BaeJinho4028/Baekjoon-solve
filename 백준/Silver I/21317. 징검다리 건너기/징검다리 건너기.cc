#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;
pair<int, int> a[25];
int d[25][2];

int f(int x, int y) {
	if (x > n) return '????';
	if (x == n) return 0;

	int& ret = d[x][y];
	if (~ret) return ret;

	ret = min(f(x + 1, y) + a[x].X, f(x + 2, y) + a[x].Y);
	if (!y) ret = min(ret, f(x + 3, 1) + k);

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i].X >> a[i].Y;
	}
	cin >> k;

	memset(d, -1, sizeof(d));
	cout << f(1, 0);
}