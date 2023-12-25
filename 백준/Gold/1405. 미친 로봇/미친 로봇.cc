#include <bits/stdc++.h>
using namespace std;

int n;
double dir[4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = { 1,-1,0,0 };
bool vis[30][30];

double dfs(int cur, int x, int y) {
	if (cur == n) return 1.0;

	vis[x][y] = true;
	double res = 0.0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (vis[nx][ny]) continue;
		res = res + dir[i] * dfs(cur + 1, nx, ny);
	}
	vis[x][y] = false;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		dir[i] = x / 100.0;
	}

	cout.precision(10);
	cout << fixed << dfs(0, 15, 15);
}