#include <bits/stdc++.h>
using namespace std;

int a[3], mx[3], mn[3], tmp[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cin >> a[0] >> a[1] >> a[2];

	mx[0] = mn[0] = a[0];
	mx[1] = mn[1] = a[1];
	mx[2] = mn[2] = a[2];

	for (int i = 1; i < n; i++) {
		cin >> a[0] >> a[1] >> a[2];

		tmp[0] = mx[0];
		tmp[1] = mx[1];
		tmp[2] = mx[2];

		mx[0] = max(tmp[0], tmp[1]) + a[0];
		mx[1] = max({ tmp[0], tmp[1], tmp[2] }) + a[1];
		mx[2] = max(tmp[1], tmp[2]) + a[2];

		tmp[0] = mn[0];
		tmp[1] = mn[1];
		tmp[2] = mn[2];

		mn[0] = min(tmp[0], tmp[1]) + a[0];
		mn[1] = min({ tmp[0], tmp[1], tmp[2] }) + a[1];
		mn[2] = min(tmp[1], tmp[2]) + a[2];
	}

	cout << max({ mx[0], mx[1], mx[2] }) << ' ' << min({ mn[0], mn[1], mn[2] });
}