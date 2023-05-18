#include <bits/stdc++.h>
using namespace std;

long long a[105][105], d[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	d[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int jump = a[i][j];
			if (i != n && i + jump <= n)
				d[i + jump][j] += d[i][j];
			if (j != n && j + jump <= n)
				d[i][j + jump] += d[i][j];
		}
	}
	cout << d[n][n];
}