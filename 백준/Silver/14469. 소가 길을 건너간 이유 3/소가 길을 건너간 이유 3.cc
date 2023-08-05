#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;


	int t = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (t < v[i].first) t = v[i].first;
		t += v[i].second;
	}

	cout << t;
}