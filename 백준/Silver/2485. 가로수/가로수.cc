#include <bits/stdc++.h>
using namespace std;

int a[100005], d[100005];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n - 1; i++)
		d[i] = a[i + 1] - a[i];

	int tmp = gcd(d[0], d[1]);

	for (int i = 2; i < n; i++) {
		tmp = gcd(tmp, d[i]);
	}


	cout << (a[n - 1] - a[0]) / tmp - n + 1;
}