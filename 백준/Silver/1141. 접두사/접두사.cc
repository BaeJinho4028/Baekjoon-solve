#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string s[55];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);

	int cnt = n;
	for (int i = 0; i < n; i++) {
		string tmp = s[i + 1].substr(0, s[i].size());
		if (tmp == s[i])
			cnt--;
	}

	cout << cnt;
}