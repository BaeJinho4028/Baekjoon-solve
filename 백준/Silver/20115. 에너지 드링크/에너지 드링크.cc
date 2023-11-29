#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

double a[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	double ans = a[n - 1];
	for (int i = 0; i < n - 1; i++) {
		ans += a[i] / 2;
	}
	cout << ans;
}