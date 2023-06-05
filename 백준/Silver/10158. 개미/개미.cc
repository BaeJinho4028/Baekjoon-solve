#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;
	
	int x = p + t;
	int y = q + t;

	if ((x / w) % 2 == 0) // +방향? -방향?
		cout << x % w << ' ';
	else
	 	cout << w - (x % w) << ' ';


	if ((y / h) % 2 == 0)
		cout << y % h;
	else
		cout << h - (y % h);
}