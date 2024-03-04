#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[10005];
ll n, m;

bool chk(ll x) {
	ll cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += x / a[i] + 1;
	}
	return cnt >= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	ll mx = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	
	if (n <= m) {
		cout << n;
		return 0;
	}

	ll st = 0, en = mx * n;
	while (st <= en) {
		ll mid = (st + en) / 2;
		if (chk(mid)) en = mid - 1;
		else st = mid + 1;
	}

	ll tmp = 0;
	for (int i = 0; i < m; i++) {
		tmp += (st - 1) / a[i] + 1;
	}
	for (int i = 0; i < m; i++) {
		if (st % a[i] == 0) {
			tmp++;
			if (tmp == n) {
				cout << i + 1;
				return 0;
			}
		}
	}
}