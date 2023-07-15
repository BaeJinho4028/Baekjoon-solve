#include <bits/stdc++.h>
using namespace std;

int n, m, ans, sum;
int a[105], c[105];
int d[105][10005]; //i번째까지 앱까지 확인했을때 j 비용으로 얻는 최대 메모리

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) 
		cin >> c[i];
	

	int mn = 0x7f7f7f7f;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			d[i][j] = d[i - 1][j];

			if (j-c[i] >= 0)
				d[i][j] = max(d[i][j], d[i - 1][j - c[i]] + a[i]);

			if (d[i][j] >= m) mn = min(mn, j);

		}
	}

	cout << mn;
}