#include <bits/stdc++.h>
using namespace std;

int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s = "IOI";
	string a;

	int n, m;
	cin >> n >> m;
	cin >> a;

	for (int i = 0; i < n-1; i++) {
		s += "OI";
	}

	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < s.size(); j++) {
			if (a[i + j] != s[j]) {
				flag = true;
				break;
			}
		}
		if (!flag) ans++;
	}

	cout << ans;
}