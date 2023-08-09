#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) v.push_back(i);
	}

	if (v.size() < k) {
		cout << -1;
		return 0;
	}

	int ans = '????';
	for (int i = 0; i < v.size() - k + 1; i++) {
		ans = min(ans, v[i + k - 1] - v[i] + 1);
	}
	cout << ans;
}