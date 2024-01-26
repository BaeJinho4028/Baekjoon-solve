#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[5005];
int tmp;

bool chk(int x) {
	int cnt = 1;
	int mx = a[0], mn = a[0];
	for (int i = 1; i < n; i++) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);

		if (mx - mn > x) {
			cnt++;
			mx = a[i], mn = a[i];
		}
	}

	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tmp = max(tmp, a[i]);
	}
	
	int st = 0, en = tmp;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (chk(mid)) en = mid - 1;
		else st = mid + 1;
	}

	cout << st << '\n';
}