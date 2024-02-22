#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;
string s;
map<string, bool> vis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s += c;
	}

	string ans = s;
	sort(ans.begin(), ans.end());

	queue<pair<string, int>> q;
	q.push({ s, 0 });
	vis[s] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur.X == ans) {
			cout << cur.Y;
			return 0;
		}

		for (int i = 0; i <= n - k; i++) {
			string tmp = cur.X.substr(i, k);

			reverse(tmp.begin(), tmp.end());

			string nxt = cur.X.substr(0, i) + tmp + cur.X.substr(i + k);

			if (vis[nxt]) continue;

			q.push({ nxt, cur.Y + 1 });
			vis[nxt] = true;

		}
	}
	cout << -1;
	return 0;
}