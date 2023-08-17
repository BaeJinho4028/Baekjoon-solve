#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

void dfs(int cur, int num, string s) {
	if (cur == n + 1) {
		if (num == 0) {
			v.push_back(s.substr(1));
		}
		return;
	}

	dfs(cur + 1, num + cur, s + "+" + to_string(cur));
	if (cur + 2 <= n + 1) 
		dfs(cur + 2, num + (cur * 10 + cur + 1), s + "+" + to_string(cur) + " " + to_string(cur + 1));
	if (cur == 1) return;

	dfs(cur + 1, num - cur, s + "-" + to_string(cur));
	if (cur + 2 <= n + 1) 
		dfs(cur + 2, num - (cur * 10 + cur + 1), s + "-" + to_string(cur) + " " + to_string(cur + 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		v.clear();

		dfs(1, 0, "");

		sort(v.begin(), v.end());
		for (auto x : v)
			cout << x << '\n';
		cout << '\n';
	}
}