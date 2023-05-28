#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;

	while (cin >> s >> t) {
		int cnt = 0;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == s[cnt])
				cnt++;
		}

		if (cnt == s.size()) cout << "Yes\n";
		else cout << "No\n";
	}
}