#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n, m;

bool solve(int mid) {
	int cur = 0, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] > mid) return false;

		if (a[i] > cur) cur = mid, cnt++;
		cur -= a[i];
	}
	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int st = 0, en = 0x7f7f7f7f;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (solve(mid)) en = mid - 1;
		else st = mid + 1;
	}

	cout << st;
}