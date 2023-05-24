#include <bits/stdc++.h>
using namespace std;

bool chk[205][205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		chk[a][b] = chk[b][a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (chk[i][j]) continue;
			for (int k = j + 1; k <= n; k++) {
				if (chk[i][k] || chk[j][k]) continue;
				ans++;
			}
		}
	}

	cout << ans;
}