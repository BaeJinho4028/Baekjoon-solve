#include <bits/stdc++.h>
using namespace std;

int d[10005];
int a[25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		fill(a, a + 25, 0);
		fill(d, d + 10005, 0);

		for (int i = 1; i <= n; i++)
			cin >> a[i];

		int cost;
		cin >> cost;

		d[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= cost; j++) {
				d[j] += d[j - a[i]];
			}
		}

		cout << d[cost] << '\n';
	}
}