#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int d[405][405];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	memset(d, '????', sizeof(d));
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	while (m--) {
		int a, b;
		cin >> a >> b;

		d[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	int s;
	cin >> s;
	while (s--) {
		int a, b;
		cin >> a >> b;

		if (d[a][b] != '????') {
			cout << -1 << '\n';
			continue;
		}
		if (d[b][a] != '????') {
			cout << 1 << '\n';
			continue;
		}
		cout << 0 << '\n';
	}

}