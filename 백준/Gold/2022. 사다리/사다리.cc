#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double x, y, c;

// c = h1*h2 /(h1+h2)
bool chk(double a) {
	double h1 = sqrt(x * x - a * a);
	double h2 = sqrt(y * y - a * a);

	double tmp = h1 * h2 / (h1 + h2);

	return tmp >= c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y >> c;

	double st = 0, en = min(x, y);
	double ans = 0;
	while (en - st > 0.0001) {
		double mid = (st + en) / 2;
		if (chk(mid)) {
			st = mid;
			ans = mid;
		}
		else en = mid;
	}
	cout << fixed;
	cout.precision(3);
	cout << en;
}