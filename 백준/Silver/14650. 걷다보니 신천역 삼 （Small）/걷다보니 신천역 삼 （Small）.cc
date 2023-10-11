#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int d[15][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[1][0] = 0;
	d[1][1] = 1;
	d[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			d[i][j] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2];
		}
	}
	cout << d[n][0];
}