#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		v.push_back(x);
	}

	sort(v.begin(), v.end());

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		ans += abs((i + 1) - v[i]);
	}

	cout << ans;
}