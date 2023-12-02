#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s = "";
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;

			if (s[0] < c)
				s += c;
			else
				s = c + s;
		}

		cout << s << '\n';
	}
}