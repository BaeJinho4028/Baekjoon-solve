#include <bits/stdc++.h>
using namespace std;

int n, l, r, x;
int ans;
int arr[1000005];

void bt(int cur, int sum, int mn, int mx, int cnt) {
	if (cur == n) {
		if (sum >= l && sum <= r && mx - mn >= x && cnt > 1)
			ans++;
		return;
	}

	int tmp = arr[cur];
	bt(cur + 1, sum + tmp, min(mn, tmp), max(mx, tmp), cnt + 1);
	bt(cur + 1, sum, mn, mx, cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bt(0, 0, '????', 0, 0);

	cout << ans;
}