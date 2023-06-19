#include <bits/stdc++.h>
using namespace std;

long long d[20][20];
int n, m, k, cx, cy;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	d[1][1] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			d[i][j] += d[i - 1][j] + d[i][j - 1];

	if (k % m != 0) {
		cy = k % m;
		cx = (k - cy) / m + 1;
	}
	else {
		cy = m;
		cx = k / m;
	}

	if (k) cout << d[cx][cy] * d[n - cx + 1][m - cy + 1];
	else cout << d[n][m];
}