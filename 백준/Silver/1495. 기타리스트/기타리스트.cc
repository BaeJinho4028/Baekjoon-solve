#include <bits/stdc++.h>
using namespace std;

int v[55];
int d[55][1005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, m;
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	d[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (d[i - 1][j] == 1) {
				if (j + v[i] <= m) d[i][j + v[i]] = 1;
				if (j - v[i] >= 0) d[i][j - v[i]] = 1;
			}
		}
	}

	for (int i = m; i >= 0; i--) {
		if (d[n][i] == 1) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << -1;
}