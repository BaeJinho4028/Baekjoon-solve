#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll f[25];
bool chk[25];
ll ans;

/*
예제 4 2 3 1

1 ? ? ? 3!개
2 ? ? ? 3!개
3 ? ? ? 3!개
4 1 ? ? 2!개
4 2 1 ? 1!개
4 2 3 1  = 총 21번째

*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, t;
	cin >> n >> t;

	f[0] = 1;
	for (int i = 1; i <= n; i++) 
		f[i] = f[i - 1] * i;

	vector<ll> comb(n + 1);

	if (t == 1) {
		ll k;
		cin >> k;

		for (int i = 1; i <= n; i++) { //i번째 자리
			for (int j = 1; j <= n; j++) { //수
				if (chk[j]) continue;

				if (f[n - i] < k) {
					k -= f[n - i];
				}
				else {
					comb[i] = j;
					chk[j] = true;
					break;
				}
			}
		}

		for (int i = 1; i <= n; i++)
			cout << comb[i] << ' ';
	}
	else {
		for (int i = 1; i <= n; i++)
			cin >> comb[i];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < comb[i]; j++) {
				if (chk[j]) continue;
				ans += f[n - i];
			}
			chk[comb[i]] = true;
		}

		cout << ans + 1 << '\n';
	}
}