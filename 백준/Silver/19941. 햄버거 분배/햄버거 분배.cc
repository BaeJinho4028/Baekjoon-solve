#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, ans = 0;
	cin >> n >> k;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] != 'P') continue;

		for (int j = i - k; j <= i + k; j++) {
			if (j < 0 || j >= n) continue;
			if (s[j] != 'H') continue;
			s[j] = '.';
			ans++;
			break;
		}
	}
	cout << ans;
}