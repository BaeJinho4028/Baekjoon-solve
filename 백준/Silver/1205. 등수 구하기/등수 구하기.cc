#include <bits/stdc++.h>
using namespace std;

int a[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;

	for (int i = 0; i <n; i++) {
		cin >> a[i];
	}

	int ans = 1, i;
	for ( i = 0; i < n; i++) {
		if (a[i] > m) ans++;
		else if (a[i] < m) break;
	}

	if (i == p) cout << -1;
	else if (n == 0) cout << 1;
	else cout << ans;
}