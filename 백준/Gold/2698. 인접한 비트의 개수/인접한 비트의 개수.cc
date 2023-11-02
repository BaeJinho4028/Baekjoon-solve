#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int d[105][105][2];
// n, k, 마지막bit

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	d[1][0][0] = 1;
	d[1][0][1] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < i; j++) {
			d[i][j][0] = d[i - 1][j][0] + d[i - 1][j][1];
			d[i][j][1] = d[i - 1][j][0] + d[i - 1][j - 1][1];
		}
	}

	while (t--) {
		int n, k;
		cin >> n >> k;

		cout << d[n][k][0] + d[n][k][1] << '\n';
	}
}