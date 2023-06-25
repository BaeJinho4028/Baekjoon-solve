#include <bits/stdc++.h>
using namespace std;

int n, ans;
int az[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int pow = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			az[s[i] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(az, az + 26, greater<>());

	int num = 9;
	for (int i = 0; i < 26; i++) {
		if (az[i] == 0) break;
		ans += az[i] * num--;
	}

	cout << ans;
}