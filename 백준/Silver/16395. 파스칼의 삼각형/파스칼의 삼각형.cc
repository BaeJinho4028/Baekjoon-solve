#include <bits/stdc++.h>
using namespace std;

int d[35][35];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	d[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}

	cout << d[n][k];
}