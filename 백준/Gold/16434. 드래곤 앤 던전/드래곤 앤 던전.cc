#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
ll n, h;
pair<ll, pair<ll, ll>> r[1000005];

bool chk(ll maxHp) {
	ll curHp = maxHp;
	ll curAtk = h;
	for (int i = 0; i < n; i++) {
		if (r[i].X == 1) {
			ll mAtk = r[i].Y.X;
			ll mHp = r[i].Y.Y;

			ll div = mHp / curAtk;
			if (mHp % curAtk == 0) div--;

			curHp -= div * mAtk;
			if(curHp <= 0) return false;
		}
		else {
			curAtk += r[i].Y.X;
			curHp = min(maxHp, curHp + r[i].Y.Y);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h;
	
	ll a, b, c;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		r[i] = { a, {b, c} };
		mx += b*c;
	}

	ll st = 1, en = 1e18;

	while (st <= en) {
		ll mid = (st + en) / 2;
		if (chk(mid)) en = mid - 1;
		else st = mid + 1;
	}
	cout << st;

	return 0;
}