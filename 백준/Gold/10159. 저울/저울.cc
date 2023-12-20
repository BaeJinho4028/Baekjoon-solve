#include <bits/stdc++.h>
using namespace std;

int f[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		f[a][b] = 1;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f[i][k] && f[k][j]) f[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (!f[i][j] && !f[j][i]) cnt++;
		}

		cout << cnt << '\n';
	}

}