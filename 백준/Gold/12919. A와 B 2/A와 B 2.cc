#include <bits/stdc++.h>
using namespace std;

string s, t;

void solve(string cur) {
	if (s == cur) {
		cout << 1;
		exit(0);
	}

	if (s.size() > cur.size()) return;

	if (cur[cur.size() - 1] == 'A') {
		string tmp = cur;
		tmp.erase(tmp.size() - 1);
		solve(tmp);
	}

	if (cur[0] == 'B') {
		string tmp = cur;
		reverse(tmp.begin(), tmp.end());
		tmp.erase(tmp.size() - 1);
		solve(tmp);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	solve(t);

	cout << 0;
}