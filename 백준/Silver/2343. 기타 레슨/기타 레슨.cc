#include <bits/stdc++.h>
using namespace std;

int a[100005];
int st, en;
int n, m;

bool solve(int x) {
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		sum += a[i];
		if (sum + a[i + 1] > x) {
			sum = 0;
			cnt++;
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
		en += a[i];
	}
	st = *max_element(a, a + n);

	while (st <= en) {
		int mid = (st + en) / 2;

		if (solve(mid)) en = mid - 1;
		else st = mid+1;
	}

	cout << st;
}