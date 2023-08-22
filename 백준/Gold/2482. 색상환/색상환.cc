#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003

int d[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		d[i][1] = i;
		for (int j = 2; j <= k; j++) {
			d[i][j] = (d[i - 1][j] + d[i - 2][j - 1]) % MOD;
		}
	}

	cout << d[n][k];
}