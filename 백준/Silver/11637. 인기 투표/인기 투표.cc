#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int sum = 0, mx = 0, idx = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;

			sum += x;

			if (mx < x) {
				mx = x;
				idx = i;
			}
			else if (mx == x) {
				idx = -1;
			}
		}

		if (idx == -1) cout << "no winner\n";
		else if (mx * 2 > sum) cout << "majority winner " << idx << '\n';
		else cout << "minority winner " << idx << '\n';
	}
}
