#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	if (b * c < a * d) { // b/a < d/c 
		swap(a, c);
		swap(b, d);
	}

	int tmp = lcm(a, c) / a;
	ll ans = LLONG_MAX;

	for (int i = 0; i < tmp; i++) {
		ll cnt = i * b;
		if (n - (i * a) > 0) cnt += (((n - (i * a) - 1) / c) + 1) * d;
		ans = min(ans, cnt);
	}
	cout << ans;
}