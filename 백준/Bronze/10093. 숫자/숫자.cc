#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c, d;

	cin >> c >> d;

	if (c > d) {
		a = d;
		b = c;
	}
	else {
		a = c;
		b = d;
	}

	if (a != b) cout << b - a - 1 << '\n';
	else cout << 0;
	for (long long i = a + 1; i < b; i++) {
		cout << i << ' ';
	}
}