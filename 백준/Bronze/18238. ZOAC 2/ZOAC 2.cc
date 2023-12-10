#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char c = 'A';

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int d = abs(s[i] - c);
		ans += min(d, 26 - d);
		c = s[i];
	}

	cout << ans;
}