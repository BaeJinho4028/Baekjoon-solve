#include <bits/stdc++.h>
using namespace std;

string s[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		if (n > 32) {
			cout << 0 << '\n';
			continue;
		}

		int mn = '????';
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				for (int k = j+1; k < n; k++) {

					int tmp = 0;
					for (int l = 0; l < 4; l++) {
						tmp += ((s[i][l] != s[j][l]) + (s[j][l] != s[k][l]) + (s[k][l] != s[i][l]));
					}

					mn = min(mn, tmp);
				}
			}
		}

		cout << mn << '\n';
	}
}