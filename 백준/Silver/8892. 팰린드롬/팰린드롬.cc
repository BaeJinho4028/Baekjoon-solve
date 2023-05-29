#include <bits/stdc++.h>
using namespace std;

string s[105];
int n;

bool chk(string t) {
	for (int i = 0; i < t.size() / 2; i++) {
		if (t[i] != t[t.size() - 1 - i])
			return false;
	}
	return true;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (chk(s[i] + s[j])) {
				cout << s[i] + s[j] << '\n';
				return;
			}
		}
	}
	cout << 0 << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> s[i];

		solve();
	}
}