#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	char c;
	cin >> n >> c >> m;

	cout << n / gcd(n, m) << ':' << m / gcd(n, m);
}