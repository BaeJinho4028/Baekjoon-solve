#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n, ans;
	cin >> a >> b >> n;

	while (n--) {
		a %= b;
		a *= 10;
		ans = a / b;
	}

	cout << ans;
}