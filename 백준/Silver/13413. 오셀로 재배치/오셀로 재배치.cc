#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

double a[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s, a;
		cin >> s >> a;

		int w = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != s[i]) {
				if (s[i] == 'W') w++;
				else if (s[i] == 'B') b++;
			}
		}

		cout << max(w, b) << '\n';
	}
}