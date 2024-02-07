#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;

		for (int j = l; j < r; j++) {
			a[j]++;
		}
	}

	int st = 0, en = 0;
	int sum = 0;
	while (st <= en && en <= 1000000) {
		if (sum == k) {
			cout << st << ' ' << en;
			return 0;
		}
		else if (sum < k) sum += a[en++];
		else sum -= a[st++];
		
	}
	cout << 0 << ' ' << 0;
}