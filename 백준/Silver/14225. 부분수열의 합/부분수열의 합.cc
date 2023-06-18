#include <bits/stdc++.h>
using namespace std;

int n;
bool chk[2000005];
int a[22];

void solve(int num, int cur) {
	chk[num] = true;
	if (cur == n) 
		return;

	solve(num + a[cur], cur + 1);
	solve(num, cur + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		solve(0, 0);
	}

	for (int i = 1; i <= 2000000; i++) {
		if (!chk[i]) {
			cout << i;
			return 0;
		}
	}
}