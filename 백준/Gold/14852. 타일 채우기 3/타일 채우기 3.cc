#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[1000005][2]; //d[x][1]에는 d[x-3][0] d[0][0]까지 합산된 값 들어감

/*
시간초과 코드

ll f(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;

	ll& ret = d[x];
	if (~ret) return ret;

	ret = 2*f(x-1) + 3*f(x-2);
	for (int i = 3; i <= x; i++) {
		ret += 2 * f(x - i);
		ret % 1000000007;
	}
	return ret;
}
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		d[i][1] = (d[i - 3][0] + d[i - 1][1]) % 1000000007;
		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % 1000000007;
	}

	cout << d[n][0];
}