#include <bits/stdc++.h>
using namespace std;

long long d[70][10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				d[i][j] += d[i - 1][k];
			}
		}
	}

	while (t--) {
		int n;
		cin >> n;

		long long ans = 0;

		for (int i = 0; i <= 9; i++)
			ans += d[n][i];

		cout << ans << '\n';
	}
}
