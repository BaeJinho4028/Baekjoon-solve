#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

ll d[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			d[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (d[i - 1][j] + d[i][j - 1] > 1000000000) d[i][j] = 0x3f3f3f3f3f3f3f3f;
			else d[i][j] = d[i - 1][j] + d[i][j - 1];
		}
	}

	if (d[n][m] < k) {
		cout << -1;
		return 0;
	}
	
	while (n > 0 && m > 0 ) {
		ll tmp = d[n - 1][m]; //첫자리 a인 문자열 개수

		if (k <= tmp) {
			n--;
			cout << 'a';
		}
		else {
			m--;
			cout << 'z';
			k -= tmp;
		}
	}

	while (n--) cout << 'a';
	while (m--) cout << 'z';

}
