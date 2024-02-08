#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<ll, ll> m;
long long n, p, q;

ll solve(ll x) {
	if (x == 0) return 1;
	if (m[x]) return m[x];

	m[x] = solve(x / p) + solve(x / q);
	return m[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;

	cout << solve(n);
}