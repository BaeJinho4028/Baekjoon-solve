#include <bits/stdc++.h>
using namespace std;

bool chk(int a, int b, int x, int y, double r) {
	int d = ((x - a) * (x - a)) + ((y - b) * (y - b));
	if ((double)d > r * r) return false;
	else return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;

	int ans = 0;

	while (p--) {
		int a, b;
		cin >> a >> b;

		if (a >= x && a <= x + w && b >= y && b <= y + h) ans++;
		else if (chk(a, b, x, y + (h / 2), h/2)) ans++;
		else if (chk(a, b, x + w, y +(h / 2), h/2))ans++;
	}

	cout << ans;
}