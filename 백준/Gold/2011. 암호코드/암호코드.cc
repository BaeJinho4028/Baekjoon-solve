#include <bits/stdc++.h>
using namespace std;

int d[5005];
int a[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 1; i <= s.size(); i++) {
		a[i] = s[i - 1] - '0';
	}

	d[0] = 1;

	for (int i = 1; i <= s.size(); i++) {
		if (a[i] > 0) d[i] = (d[i] + d[i - 1]) % 1000000;
		int x = a[i - 1] * 10 + a[i];
		if (x>=10 && x < 27) d[i] = (d[i] + d[i - 2]) % 1000000;
	}

	cout << d[s.size()];
}