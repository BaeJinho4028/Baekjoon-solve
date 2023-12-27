#include <bits/stdc++.h>
using namespace std;

set<string> se;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	char c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		se.insert(s);
	}

	int d;
	if (c == 'Y') d = 1;
	else if (c == 'F') d = 2;
	else d = 3;

	cout << (int)se.size() / d;
}