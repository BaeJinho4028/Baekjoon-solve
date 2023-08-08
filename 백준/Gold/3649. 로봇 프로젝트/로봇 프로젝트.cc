#include <bits/stdc++.h>
using namespace std;

int x, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> x >> n) {
		x *= 10000000;

		vector<int> l;

		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			l.push_back(t);
		}
		sort(l.begin(), l.end());

		int st = 0, en = n - 1;
		bool flag = false;

		while (st < en) {
			int sum = l[st] + l[en];
			if (sum == x) {
				flag = true;
				break;
			}

			if (sum < x) st++;
			else en--;
		}

		if (flag) cout << "yes " << l[st] << ' ' << l[en] << '\n';
		else cout << "danger\n";
	}
}