#include <bits/stdc++.h>
using namespace std;

string s, t, a, b;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	int tmp = lcm(s.size(), t.size());

	for (int i = 0; i < tmp / s.size(); i++)
		a += s;
	for (int i = 0; i < tmp / t.size(); i++)
		b += t;

	cout << (a == b) << '\n';
}