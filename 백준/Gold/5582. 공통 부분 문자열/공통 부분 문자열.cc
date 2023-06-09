#include <bits/stdc++.h>
using namespace std;

int d[4005][4005], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			if (s[i] == t[j]) {
				d[i + 1][j + 1] = d[i][j] + 1;
				ans = max(ans, d[i + 1][j + 1]);
			}
		}
	}

	cout << ans;
}