#include <bits/stdc++.h>
using namespace std;

int n;
char c[11];
bool vis[11];
vector<string> ans;

bool chk(char a, char b, char oper) {
	if (oper == '<') {
		if (a > b) return false;
	}
	else {
		if (a < b) return false;
	}
	return true;
}

void solve(string s, int cur) {
	if (cur == n + 1) {
		ans.push_back(s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (vis[i]) continue;
		if (cur == 0 || chk(s[cur - 1], i + '0', c[cur - 1])) {
			vis[i] = true;
			solve(s + to_string(i), cur + 1);
			vis[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> c[i];

	solve("", 0);

	sort(ans.begin(), ans.end());

	cout << ans[ans.size() - 1] << '\n' << ans[0];
}