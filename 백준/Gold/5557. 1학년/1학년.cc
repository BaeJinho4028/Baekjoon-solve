#include <bits/stdc++.h>
using namespace std;

int a[105];
long long d[105][25];

int main() { // A X B = a * b * sing a;  ad - bc (2차원이라 z값 0)
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1][a[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (d[i - 1][j]) {
				if (j + a[i] <= 20) d[i][j + a[i]] += d[i - 1][j];
				if (j - a[i] >= 0) d[i][j - a[i]] += d[i - 1][j];
			}
		}
	}

	cout << d[n - 1][a[n]];
}
