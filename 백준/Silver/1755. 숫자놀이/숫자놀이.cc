#include <bits/stdc++.h>
using namespace std;

string a[11] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<string, int>> v;
	for (int i = n; i <= m; i++) {
		if (i < 10)
			v.push_back({ a[i % 10], i });
		else
			v.push_back({ a[i / 10] + " " + a[i % 10], i });
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (auto x : v) {
		cout << x.second << ' ';
		cnt++;
		if (cnt % 10 == 0) cout << '\n';
	}
}