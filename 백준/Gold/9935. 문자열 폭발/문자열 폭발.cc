#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s, t, ans = "";
	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		ans += s[i];

		if (ans.size() >= t.size()) {
			bool flag = true; // 폭발문자열 있는지?

			for (int j = 0; j < t.size(); j++) {
				if (ans[ans.size() - t.size() + j] != t[j]) {
					flag = false; 
					break;
				}
			}

			if (flag)
				ans.erase(ans.end() - t.size(), ans.end());
		}
	}

	if (ans.empty())
		cout << "FRULA";
	else
		cout << ans;
}