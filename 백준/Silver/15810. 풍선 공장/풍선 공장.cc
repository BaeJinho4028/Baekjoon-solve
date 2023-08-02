#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m;
ll a[1000005];

bool solve(ll x) {
	ll cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += x / a[i];

	return cnt >= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	ll st = a[0], en = a[0] * m;

	while (st <= en) {
		ll mid = (st + en) / 2;
		if (solve(mid)) en = mid - 1;
		else st = mid + 1;
	}

	cout << st;
}