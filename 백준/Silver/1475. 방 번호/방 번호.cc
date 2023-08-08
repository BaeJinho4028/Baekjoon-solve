#include <bits/stdc++.h>
using namespace std; //104

int main() {
	string s;
	cin >> s;
	int num[11] = { 0, };
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6' && num[6] == 0 && num[9] > 0) {
			num[9]--;
		}
		else if (s[i] == '9' && num[6] > 0 && num[9] == 0) {
			num[6]--;
		}
		else if (num[s[i] - '0'] == 0) {
			cnt++;
			for (int j = 0; j <= 9; j++) {
				num[j]++;
			}
			num[s[i] - '0']--;
		}
		else num[s[i] - '0']--;
	}
	cout << cnt;
}