#include <bits/stdc++.h>
using namespace std;

int p[1005][7];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> p[i][j];
		}
	}

	int mx = 0, idx =0;
	for (int i = 1; i <= n; i++) {
		int m = 0, tmp = 0;

		for (int a = 1; a <= 5; a++) {
			for (int b = a + 1; b <= 5; b++) {
				for (int c = b + 1; c <= 5; c++) {
					tmp = (p[i][a] + p[i][b] + p[i][c])%10;
					m = max(m, tmp);
				}
			}
		}

		if (mx <= m) {
			//cout << m << ' ' << i << '\n';
			mx = m;
			idx = i;
		}
	}

	cout << idx;
}