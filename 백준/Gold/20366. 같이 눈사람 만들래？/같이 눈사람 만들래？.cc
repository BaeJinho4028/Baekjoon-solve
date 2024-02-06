#include <bits/stdc++.h>
using namespace std;

int a[605];
int ans = '????';

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 3; j < n; j++) {
			int x = i + 1, y = j - 1;

			while (x < y) {
				int tmp = a[i] + a[j] - a[x] - a[y];
				ans = min(ans, abs(tmp));

				if (tmp > 0) x++;
				else y--;
			}
		}
	}

	cout << ans;
}