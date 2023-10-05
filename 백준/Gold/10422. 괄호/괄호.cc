#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l;
ll d[5005];

ll f(int x) {
	if (x == 0) return 1;

	ll& ret = d[x];
	if (~ret) return ret;
	
	ret = 0;
	for (int i = 2; i <= x; i += 2) {
		ret += f(i - 2) * f(x - i);
		ret %= 1000000007;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	memset(d, -1, sizeof(d));
	while (t--) {
		cin >> l;

		if (l % 2) cout << 0 << '\n';
		else cout << f(l) << '\n';
	}
}
