#include <bits/stdc++.h>
using namespace std;

int d[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, y;
	cin >> h >> y;

	d[0] = h;
	for (int i = 1; i <= y; i++) {
		
		d[i] = (int)(d[i - 1] * 1.05);
		if (i >= 3) {
			d[i] = max(d[i], (int)(d[i - 3] * 1.2));
		}
		if (i >= 5) {
			d[i] = max(d[i], (int)(d[i - 5] * 1.35));
		}
	}

	cout << d[y];
}
