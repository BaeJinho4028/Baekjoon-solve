#include <bits/stdc++.h>
using namespace std;

int n, mx;
vector<int> v;

void solve(int num) {
	if (v.size() == 2) {
		mx = max(mx, num);
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {
		int a = v[i - 1] * v[i + 1], b = v[i];

		v.erase(v.begin() + i);
		solve(num + a);
		v.insert(v.begin() + i, b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	solve(0);

	cout << mx;
}