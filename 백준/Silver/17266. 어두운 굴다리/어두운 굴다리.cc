#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n, m;

bool solve(int mid) {
	for (int i = 0; i < m - 1; i++) {
		if (a[i] + mid < a[i + 1] - mid) return false;
	}
	if (a[0] - mid > 0) return false;
	if (a[m - 1] + mid < n) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> a[i];

	int st = 0, en = 100000;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (solve(mid)) en = mid - 1;
		else st = mid + 1;
	}

	cout << st;
}