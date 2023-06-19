#include <bits/stdc++.h>
using namespace std;

int a[1500];
vector<int> v[10];

void solve(int d, int st, int en) {
	if (st >= en) return;

	int mid = (st + en) / 2;
	v[d].push_back(a[mid]);
	solve(d + 1, st, mid);
	solve(d + 1, mid + 1, en);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	for (int i = 0; i < (1 << k)-1; i++) {
		cin >> a[i];
	}
	solve(0, 0, (1 << k) - 1);

	for (int i = 0; i < k; i++) {
		for (auto x : v[i])
			cout << x << ' ';
		cout << '\n';
	}
}