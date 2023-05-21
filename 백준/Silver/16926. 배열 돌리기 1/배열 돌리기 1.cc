#include <bits/stdc++.h>
using namespace std;

int a[305][305];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, r;

void solve(int cnt) {
	for (int i = 0; i < cnt; i++) {
		int st = a[i][i];
		int x = i;
		int y = i;

		int k = 0;
		while (k < 4) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx == i && ny == i) break;

			if (nx >= i && nx < n - i && ny >= i && ny < m - i) {
				a[x][y] = a[nx][ny];
				x = nx;
				y = ny;
			}
			else k++;
		}
		a[i + 1][i] = st;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int cnt = min(n, m) / 2;

	for (int i = 0; i < r; i++)
		solve(cnt);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}