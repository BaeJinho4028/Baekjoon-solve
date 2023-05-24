#include <bits/stdc++.h>
using namespace std;

bool flag;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string s;
		cin >> s;

		if (s == "end") break;

		bool a = false, b = false, c = false;
		int cnt = 0, chk = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				a = true;
				cnt++;
				chk = 0;
			}
			else cnt = 0, chk++;

			if (cnt >= 3 || chk >= 3) b = true;

			if (i > 0 && s[i - 1] == s[i] && !(s[i] == 'e' || s[i] == 'o')) c = true;
		}

		//cout << a << b << c << '\n';
		cout << '<' << s << '>';
		if (!a || b || c) cout << " is not acceptable.\n";
		else cout << " is acceptable.\n";
	}

}