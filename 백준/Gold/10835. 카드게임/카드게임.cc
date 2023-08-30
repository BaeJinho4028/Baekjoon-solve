#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };
int n, m;
int mx, mn = '????';
int ans, cnt;

int d[2005][2005];
int a[2005], b[2005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = n; i > 0; i--) {
		cin >> a[i];
	}

	for (int i = n; i > 0; i--) {
		cin >> b[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]);
			if (a[i] > b[j])
				d[i][j] = max(d[i][j], d[i][j - 1] + b[j]);
		}
	}

	cout << d[n][n];
}