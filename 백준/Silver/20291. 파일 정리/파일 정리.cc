#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		s = s.substr(s.find('.') + 1);
		m[s]++;
	}

	for (auto it = m.begin(); it != m.end(); it++)
		cout << (*it).first << ' ' << (*it).second << '\n';
}