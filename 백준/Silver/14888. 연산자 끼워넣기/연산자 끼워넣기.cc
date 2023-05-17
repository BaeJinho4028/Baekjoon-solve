#include <bits/stdc++.h>
using namespace std;

int a[15], b[5];
int mn = 1000000005, mx = - 1000000005;
int n;

void solve(int ans, int cur) {
	if (cur == n) {
		mx = max(mx, ans);
		mn = min(mn, ans);

		return;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] > 0) {
			b[i]--;
			
			if (i == 0)
				solve(ans + a[cur], cur + 1);
			else if (i == 1)
				solve(ans - a[cur], cur + 1);
			else if (i == 2)
				solve(ans * a[cur], cur + 1);
			else
				solve(ans / a[cur], cur + 1);

			b[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b[0] >> b[1] >> b[2] >> b[3];

	solve(a[0], 1);

	cout << mx << '\n' << mn;
}