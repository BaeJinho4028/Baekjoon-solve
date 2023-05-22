#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int x, cnt = 0, st = 1, en = m;
	for (int i = 1; i <= k; i++) {
		cin >> x;

		while (1) {
			if (x >= st && x <= en)
				break;
			else if (x < st) {
				st--;
				en--;
			}
			else {
				st++;
				en++;
			}
			cnt++;
		}
	}

	cout << cnt;
}