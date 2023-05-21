#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	solve(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	solve(6 - a - b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s = to_string(pow(2, n));
	int x = s.find('.');
	s = s.substr(0, x);
	s[s.size() - 1] -= 1;

	cout << s << '\n';

	if (n <= 20) solve(1, 3, n);
}