#include <bits/stdc++.h>
using namespace std;

int a[500005];
long long ans = 0;

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int l = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		l += a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		ans += a[i] * (l - a[i]);
		l -= a[i];
	}

	cout << ans;
}
