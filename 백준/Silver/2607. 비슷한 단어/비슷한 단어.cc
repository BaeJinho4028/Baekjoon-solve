#include <bits/stdc++.h>
using namespace std;

int az[26];
int tmp[26];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	string s;
	cin >> s;
	n--;

	for (int i = 0; i < s.size(); i++) {
		az[s[i] - 'A']++;
	}

	while (n--) {
		string t;
		cin >> t;

		memset(tmp, 0, sizeof(tmp));

		for (int i = 0; i < t.size(); i++) {
			tmp[t[i] - 'A']++;
		}

		int cnt = 0, chk =0;
		for (int i = 0; i < 26; i++) {
			cnt += abs(az[i] - tmp[i]);
		}

		int l = s.size() - t.size();
		if (cnt <= 2 && abs(l) <= 1) ans++;
	}

	cout << ans;
}