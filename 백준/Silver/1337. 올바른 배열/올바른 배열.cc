#include <bits/stdc++.h>
using namespace std;

int a[55];
int cnt, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	cnt = 1;
	for (int i = 0; i < n; i++) {
		cnt = 1;

		for (int j = i + 1; j < i + 5; j++) {
			if (a[j] - a[i] > 0 && a[j] - a[i] < 5) cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << max(0, 5 - ans);
}