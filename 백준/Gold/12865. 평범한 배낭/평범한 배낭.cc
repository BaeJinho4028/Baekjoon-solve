#include <bits/stdc++.h>
using namespace std;

int d[105][100005]; 
int w[105];
int v[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0) 
				d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
			else d[i][j] = d[i - 1][j];
		}
	}
	cout << d[n][k];
}