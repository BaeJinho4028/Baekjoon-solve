#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n, k;
ll a[1005], b[1005];
ll d[1005][10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j - b[i] >= 0) d[i][j] = max(d[i - 1][j], d[i - 1][j - b[i]] + a[i]);
			else d[i][j] = d[i - 1][j];
		}
	}
	cout << d[k][n];
}