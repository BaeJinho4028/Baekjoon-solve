#include <bits/stdc++.h>
using namespace std;

int c, n;
int a[25], b[25];
int d[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (j - a[i] >= 0) {
				d[j] = max(d[j], d[j - a[i]] + b[i]);
			}
		}
	}

	for (int i = 1; i <= 1000000; i++) {
		if (d[i] >= c) {
			cout << i;
			break;
		}
	}
}