#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005];
int x, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		d[x] = d[x - 1] + 1;
		ans = max(ans, d[x]);
	}

	cout << n - ans;
}