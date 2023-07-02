#include <bits/stdc++.h>
using namespace std;

int az[26];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	while (n--) {
		string s;
		cin >> s;

		bool flag = false;
		
		memset(az, 0, sizeof(az));

		for (int i = 1; i < s.size(); i++) {

			az[s[i - 1] - 'a']++;
			if (s[i - 1] != s[i] && az[s[i] - 'a'] != 0) {
				flag = true;
				break;
			}
		}

		if (!flag)cnt++;
	}

	cout << cnt;
}