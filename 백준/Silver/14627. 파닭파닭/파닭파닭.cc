#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s, c;
ll a[1000005];

bool chk(int x) {
	int cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += a[i] / x;
	}
	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> c;

	ll mx = 0;
	ll ans = 0;
	for (int i = 0; i < s; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		ans += a[i];
	}

	ll st = 1, en = mx;
	while (st <= en) {
		ll mid = (st + en) / 2;
		if (chk(mid)) st = mid + 1;
		else en = mid - 1;
	}

	cout << ans - (en * c) << '\n';
}