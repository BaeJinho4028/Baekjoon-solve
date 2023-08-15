#include <bits/stdc++.h>
using namespace std;

int d[105][105][105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			for (int k = 1; k <= c.length(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
				else d[i][j][k] = max({ d[i - 1][j][k], d[i][j - 1][k], d[i][j][k - 1] });
			}
		}
	}

	cout << d[a.length()][b.length()][c.length()];
}