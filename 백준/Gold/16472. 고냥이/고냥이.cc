#include <bits/stdc++.h>
using namespace std;

int az[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int st = 0, en = 0, cnt = 0, ans = 0;;
	while (1) {
		while (cnt <= n && en < s.size()) {
			if (!az[s[en] - 'a']) cnt++;
			az[s[en++] - 'a']++;
			if (cnt > n) break;
			ans = max(ans, en - st);
		}
		if (en == s.size()) break;
		while (cnt > n) {
			az[s[st] - 'a']--;
			if (!az[s[st++] - 'a']) cnt--;
		}
	}

	cout << ans;
}