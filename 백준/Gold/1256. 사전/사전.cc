#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

ll d[205][105];

ll comb(int n, int r) {
	if (n == r || r == 0) return 1;
	ll& ret = d[n][r];
	if (~ret) return d[n][r];

	ll a = comb(n - 1, r - 1);
	ll b = comb(n - 1, r);
	if (a + b > 1000000000) return ret = 0x3f3f3f3f3f3f3f3f;

	return d[n][r] = comb(n-1, r-1) + comb(n - 1, r);
}

void f(int n, int m, ll k) {
	ll tmp = comb(n + m - 1, n - 1);
	if (n > 0 && k <= tmp) {
		cout << 'a';
		f(n - 1, m, k);
	}
	else if (m > 0) {
		cout << 'z';
		f(n, m - 1, k - tmp);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	memset(d, -1, sizeof(d));

	if (comb(n+m, min(n,m)) < k) {
		cout << -1;
		return 0;
	}
	
	f(n, m, k);
}
