#include <bits/stdc++.h>
using namespace std;

int a[55];
int cnt[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		double mx = -'????';
		for (int j = i + 1; j < n; j++) {
			double tmp = (double)(a[j] - a[i]) / (j - i);
			if (tmp > mx) {
				cnt[i]++;
				cnt[j]++;
				mx = tmp;
			}
		}
	}

	int ans = 0;
	for (auto x : cnt)
		ans = max(ans, x);

	cout << ans;
}