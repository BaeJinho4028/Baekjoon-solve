#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

ll n, m;
ll a[100005];
ll mx;

bool solve(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += mid / a[i];

	return cnt >= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	ll st = 1, en = mx * m;

	while (st <= en) {
		ll mid = (st + en) / 2;
		if (solve(mid)) en = mid - 1;
		else st = mid + 1;
	}

	cout << st;
}