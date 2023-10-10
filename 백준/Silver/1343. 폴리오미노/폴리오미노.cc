#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') cnt++;
		
		if (cnt == 4) {
			for (int j = 0; j < 4; j++)
				s[i - j] = 'A';
			cnt = 0;
		}
		if (cnt == 2 && s[i + 1] != 'X') {
			for (int j = 0; j < 2; j++)
				s[i - j] = 'B';
			cnt = 0;
		}
	}

	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') flag = true;
	}

	if (flag) cout << -1;
	else cout << s;
}
