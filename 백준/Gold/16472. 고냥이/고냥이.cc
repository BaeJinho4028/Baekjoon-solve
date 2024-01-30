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
	
	while(en < s.size()) {
		if (!az[s[en] - 'a']) cnt++;
		az[s[en] - 'a']++;

		while (cnt > n) {
			az[s[st] - 'a']--;
			if (!az[s[st] - 'a']) cnt--;
			st++;
		}

		ans = max(ans, en - st + 1);
		en++;
	}

	cout << ans;
}