#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int n;
	cin >> n;

	while (n--) {
		char a;
		int b, c;
		cin >> a >> b >> c;

		int cnt = 0;
		for (int i = b; i <= c; i++) {
			if (s[i] == a) cnt++;
		}

		cout << cnt << '\n';
	}
}