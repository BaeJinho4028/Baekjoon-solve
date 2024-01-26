#include <bits/stdc++.h>
using namespace std;

int n, k;
int vs[15][15];
int h[3][25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> vs[i][j];
		}
	}

	for (int i = 0; i < 20; i++)
		cin >> h[1][i];
	for (int i = 0; i < 20; i++)
		cin >> h[2][i];
	for (int i = 0; i < n; i++)
		h[0][i] = i + 1;

	do {
		int win[3] = { 0, };
		int idx[3] = { 0, };
		int a = 0, b = 1;
		while (1) {
			if (a > b) swap(a, b);
			if (a == 0 && idx[0] >= n)
				break;

			int res = vs[h[a][idx[a]++]][h[b][idx[b]++]];
			if (res == 2) {
				win[a]++;
				if (win[a] == k) break;
				b = 3 - a - b;
			}
			else {
				win[b]++;
				if (win[b] == k) break;
				a = 3 - a - b;
			}
		}

		if (win[0] == k) {
			cout << 1;
			return 0;
		}
	} while (next_permutation(h[0], h[0] + n));

	cout << 0;
	return 0;
}