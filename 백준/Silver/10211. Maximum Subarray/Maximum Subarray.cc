#include <bits/stdc++.h>
using namespace std;

int d[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> d[i];

		for (int i = 1; i < n; i++) {
			d[i] = max(0, d[i - 1]) + d[i];
		}

		cout << *max_element(d, d + n) << '\n';
	}
}