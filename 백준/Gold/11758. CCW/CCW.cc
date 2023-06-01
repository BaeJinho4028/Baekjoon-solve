#include <bits/stdc++.h>
using namespace std;

int main() { // A X B = a * b * sing a;  ad - bc (2차원이라 z값 0)
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int d = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if (d > 0) cout << 1;
	else if (d < 0)cout << -1;
	else cout << 0;
}
