#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m;
ll a[300005];
ll mx;

bool solve(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += a[i] / mid;
		if (a[i] % mid) cnt++;
	}

	return cnt > n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	ll st = 1, en = mx * m;

	while (st <= en) {
		ll mid = (st + en) / 2;
		if (solve(mid)) st = mid + 1;
		else en = mid - 1;
	}

	cout << st;
}