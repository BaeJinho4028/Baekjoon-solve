#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n <= k) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	while (1) {
		int cnt = 0, tmp = n;

		while (tmp) {
			if (tmp % 2 != 0)
				cnt++;
			tmp /= 2;
		}

		if (k >= cnt) break;

		n++;
		ans++;
	}

	cout << ans;
}