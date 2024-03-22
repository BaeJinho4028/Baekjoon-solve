#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long x, y, w, s;
	cin >> x >> y >> w >> s;

	long long tmp = max(x, y) - min(x, y);

	long long t = min(x, y) * min(2 * w, s);

	t += (tmp / 2) * min(2 * w, 2 * s) + (tmp % 2) * w;

	cout << t;
}