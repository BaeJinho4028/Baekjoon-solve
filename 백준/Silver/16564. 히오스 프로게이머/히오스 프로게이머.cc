#include <bits/stdc++.h>
using namespace std;

long long a[1000005];
long long n, k;

bool solve(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += max((long long)0, mid - a[i]);
	}

	return k >= cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	long long st = 1, en = 0x7f7f7f7f7f;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	while (st <= en) {
		long long mid = (st + en) / 2;
		if (solve(mid)) st = mid + 1;
		else en = mid - 1;
	}

	cout << en;
}