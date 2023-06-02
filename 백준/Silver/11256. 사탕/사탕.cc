#include <bits/stdc++.h>
using namespace std;

int a[1005], ans;

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int j, n;
		cin >> j >> n;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a[i] = x * y;
		}

		sort(a, a + n);

		for (int i = 0; i < n; i++) {
			j -= a[n - i - 1];
			if (j <= 0) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}
