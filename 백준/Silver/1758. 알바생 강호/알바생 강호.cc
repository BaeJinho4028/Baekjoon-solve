#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, greater<>());

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int x = a[i] - i;
		if (x > 0) ans += x;
	}

	cout << ans;
}