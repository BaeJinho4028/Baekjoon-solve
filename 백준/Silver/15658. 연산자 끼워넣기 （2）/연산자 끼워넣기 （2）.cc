#include <bits/stdc++.h>
using namespace std;

int a[15];
int o[5];
int n, mx = -0x7f7f7f7f, mn = 0x7f7f7f7f;

void solve(int num, int cur) {
	if (cur == n) {
		mx = max(mx, num);
		mn = min(mn, num);
		return;
	}

	if (o[0]) {
		o[0]--;
		solve(num + a[cur], cur + 1);
		o[0]++;
	}
	if (o[1]) {
		o[1]--;
		solve(num - a[cur], cur + 1);
		o[1]++;
	}
	if (o[2]) {
		o[2]--;
		solve(num * a[cur], cur + 1);
		o[2]++;
	}
	if (o[3]) {
		o[3]--;
		solve(num / a[cur], cur + 1);
		o[3]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> o[i];

	solve(a[0], 1);

	cout << mx << '\n' << mn;
}