#include <bits/stdc++.h>
using namespace std;

int d[100005][2], a[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, mx;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[1][0] = d[1][1] = mx = a[1];


	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][0] + a[i], a[i]);
		d[i][1] = max(d[i - 1][0], d[i - 1][1] + a[i]);
		mx = max(mx, max(d[i][0], d[i][1]));
	}

	cout << mx;
}