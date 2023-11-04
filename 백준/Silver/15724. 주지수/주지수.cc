#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int d[1055][1055]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a;
		}
	}

	int k;
	cin >> k;

	while (k--) {
		int x, y, z, w;
		cin >> x >> y >> z >> w;

		cout << d[z][w] - d[x - 1][w] - d[z][y - 1] + d[x - 1][y - 1] << '\n';
	}
}