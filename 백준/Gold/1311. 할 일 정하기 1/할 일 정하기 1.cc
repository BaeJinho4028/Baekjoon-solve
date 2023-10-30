#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n;
int a[25][25];
int d[25][1 << 20];

int f(int cur, int bit) {
	if (bit == (1 << n) - 1) return 0;

	int& ret = d[cur][bit];
	if (~ret) return ret;

	ret = '????';
	for (int i = 0; i < n; i++) {
		if (bit & (1 << i)) continue;
		
		ret = min(ret, f(cur + 1, bit | (1 << i)) + a[cur][i]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	memset(d, -1, sizeof(d));
	cout << f(0, 0);
}