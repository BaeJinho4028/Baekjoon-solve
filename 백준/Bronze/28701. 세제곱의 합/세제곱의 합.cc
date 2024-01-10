#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		a += i;
		c += i * i * i;
	}
	b = a*a;

	cout << a << '\n' << b << '\n' << c;
}