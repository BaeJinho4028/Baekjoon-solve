#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];
int d[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = max({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] }) + a[i][j];
		}
	}
	cout << d[n][m];
}