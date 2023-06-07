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

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if ((i+1) % 3 == 0) continue;
		ans += a[i];
	}

	cout << ans;
}