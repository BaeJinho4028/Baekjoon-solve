#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int m;
		cin >> m;

		priority_queue<int> mn;
		priority_queue<int, vector<int>, greater<int>> mx;
		vector<int> v;

		int mid;
		for (int i = 1; i <= m; i++) {
			int x;
			cin >> x;
			if (i == 1) mid = x;
			else {
				if (mid > x) mn.push(x);
				else mx.push(x);
			}

			if (i % 2 == 1) {
				if (mx.size() > mn.size()) {
					mn.push(mid);
					mid = mx.top();
					mx.pop();
				}
				if (mx.size() < mn.size()) {
					mx.push(mid);
					mid = mn.top();
					mn.pop();
				}

				v.push_back(mid);
			}
		}

		cout << v.size() << '\n';
		for (int i = 1; i <= v.size(); i++) {
			cout << v[i-1] << ' ';
			if (i % 10 == 0) cout << '\n';
		}
		cout << '\n';
	}
}