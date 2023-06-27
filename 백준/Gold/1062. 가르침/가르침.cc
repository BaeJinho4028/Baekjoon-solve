#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans;
bool az[26];
vector<string> v;

int chk() {
	int cnt = 0;

	for (auto a : v) {
		bool flag = true;
		for (int i = 0; i < a.size(); i++) {
			if (!az[a[i] - 'a']) flag = false;
		}
		if (flag) cnt++;
	}
	return cnt;
}

void dfs(int cur, int st) {
	if (cur == k) {
		ans = max(ans, chk());
		return;
	}

	for (int i = st; i < 26; i++) {
		if (az[i]) continue;

		az[i] = true;
		dfs(cur + 1, i);
		az[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	az['a' - 'a'] = 1;
	az['n' - 'a'] = 1;
	az['t' - 'a'] = 1;
	az['i' - 'a'] = 1;
	az['c' - 'a'] = 1;

	k -= 5;

	while (n--) {
		string s;
		cin >> s;

		if (k < 0) {
			cout << 0;
			return 0;
		}



		s = s.substr(4, s.size() - 8);
		v.push_back(s);
	}

	dfs(0, 0);

	cout << ans;
}