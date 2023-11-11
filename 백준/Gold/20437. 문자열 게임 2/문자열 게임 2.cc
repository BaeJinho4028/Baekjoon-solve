#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int az[26], chk[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int k;
		cin >> k;

		memset(az, 0, sizeof(az));
		memset(chk, -1, sizeof(chk));

		int mn = '????', mx = 0;
		int pos, tmp, len;
		for (int i = 0; i < s.size(); i++) {
			pos = s[i] - 'a';
			az[pos]++;

			if (az[pos] >= k) {
				if (chk[pos] == -1) // 처음 k개가 되었을 경우
					tmp = s.find(s[i]);
				else //이전에 이미 k개가 되었을경우
					tmp = s.find(s[i], chk[pos] + 1);

				chk[pos] = tmp;
				len = (i - chk[pos]) + 1;
				if (len < mn) mn = len;
				if (len > mx) mx = len;
			}
		}

		if (mn == '????') cout << -1 << '\n';
		else cout << mn << ' ' << mx << '\n';
	}
}
