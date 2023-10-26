#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n;
int c[16][16];
int d[16][1 << 16];

int f(int cur, int vis) {
	if (vis == (1 << n) - 1) {
		if (c[cur][0] == 0)
			return '????';
		return c[cur][0];
	}

	int& ret = d[cur][vis];
	if (~ret) return ret;

	ret = '????';

	for (int i = 0; i < n; i++) {
		if (c[cur][i] == 0)
			continue;
		if ((vis & (1 << i)) == (1 << i))
			continue;
		ret = min(ret, c[cur][i] + f(i, vis | 1 << i));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}

	memset(d, -1, sizeof(d));
	cout << f(0, 1);
}