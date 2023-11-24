#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n, t;
int a[200005], d[200005];

bool chk(int x) {
	for (int i = 1; i <= n; i++) {
		if (i - x >= 1) 
			d[i] = max(d[i - x] + t, a[i] - t + 1);
		else 
			d[i] = max(1, a[i] - t + 1);
		

		if (d[i] > a[i]) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int l = 1, r = n;
	while (l <= r) {
		int m = (l + r) / 2;
		if (chk(m)) r = m - 1; 
		else l = m + 1;
	}
	cout << l;
}