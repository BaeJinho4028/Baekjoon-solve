#include <bits/stdc++.h>
using namespace std;

double a[10005], d[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = a[0];

	for (int i = 1; i < n; i++) {
		d[i] = max(a[i], a[i] * d[i - 1]);
	}

	cout << fixed;
	cout.precision(3);
	cout << *max_element(d, d + n);
}