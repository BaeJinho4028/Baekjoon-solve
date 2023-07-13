#include <bits/stdc++.h>
using namespace std;

int r[505], c[505], d[505][505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> r[i] >> c[i];

	for (int i = 1; i <= n; i++) { // 범위
		for (int j = 1; i + j <= n; j++) {
			d[j][i + j] = '????';
			for (int k = j; k <= i + j; k++) {
				d[j][i + j] = min(d[j][i + j], d[j][k] + d[k + 1][i + j] + r[j] * c[k] * c[i + j]);
			}
		}
	}

	cout << d[1][n];
}