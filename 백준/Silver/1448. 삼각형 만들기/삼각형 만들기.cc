#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, greater<>());

	for (int i = 2; i < n; i++) {
		if (a[i - 2] < a[i - 1] + a[i]) {
			cout << a[i - 2] + a[i - 1] + a[i];
			break;
		}
		if (i == n - 1) cout << -1;
	}
}