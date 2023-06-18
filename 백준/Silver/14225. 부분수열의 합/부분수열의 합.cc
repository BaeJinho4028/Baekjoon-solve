#include <bits/stdc++.h>
using namespace std;

int n;
set<int> se;
int a[22];

void solve(int chk, int num, int cur) {
	if (cur == chk) {
		se.insert(num);
		return;
	}

	solve(chk, num + a[cur], cur + 1);
	solve(chk, num, cur + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		solve(i, 0, 0);
	}

	for (int i = 1; i < 2000000; i++) {
		if (se.find(i) == se.end()) {
			cout << i;
			return 0;
		}
	}
}