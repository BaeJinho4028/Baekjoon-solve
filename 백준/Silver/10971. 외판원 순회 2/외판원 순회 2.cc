#include <bits/stdc++.h>
using namespace std;

int n, st;
int w[15][15];
bool vis[15];
int mn = 1e9 + 5;

void solve(int u, int cur, int cost) {
	if (cur == n) {
		if (w[u][st] != 0)
			mn = min(mn, cost + w[u][st]);

		return;
	}

	for (int i = 0; i < n; i++) {
		if (w[u][i] == 0 || vis[i]) continue;

		vis[i] = true;
		solve(i, cur + 1, cost + w[u][i]);
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		st = i;
		vis[i] = true;
		solve(i, 1, 0);
		vis[i] = false;
	}

	cout << mn;
}