#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, m;
	cin >> a >> b >> c >> m;

	int ans = 0, cnt = 0;

	for (int i = 0; i < 24; i++) {
		if (cnt + a <= m) {
			cnt += a;
			ans += b;
		}
		else {
			cnt = max(cnt - c, 0);
		}
	}

	cout << ans;
}