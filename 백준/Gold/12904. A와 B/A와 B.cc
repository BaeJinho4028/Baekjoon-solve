#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	bool flag = false;

	while (1) {
		if (s.size() == t.size()) {
			if (s == t) flag = true;
			break;
		}

		if (t[t.size() - 1] == 'A')
			t.pop_back();
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	cout << flag;
}