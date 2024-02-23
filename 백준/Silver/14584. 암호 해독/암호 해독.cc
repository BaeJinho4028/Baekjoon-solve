#include <bits/stdc++.h>
using namespace std;

string chk[25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> chk[i];
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < n; j++) {
			if (s.find(chk[j]) != string::npos) {
				cout << s;
				return 0;
			}
		}

		for (int j = 0; j < s.size(); j++) {
			s[j] = (s.at(j) - 'a' + 1) % 26 + 'a';
		}
	}

	return 0;
}