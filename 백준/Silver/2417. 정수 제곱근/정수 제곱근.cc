#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, q;

	cin >> n;

	q = sqrt(n);

	if (q * q < n) q++;

	cout << q;
}