#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (v.empty() || v.back() < x)
			v.push_back(x);
		else
			*lower_bound(v.begin(), v.end(), x) = x;
	}

	cout << n - v.size();
}