#include <bits/stdc++.h>
using namespace std;

int n, m, h;
bool vis[35][15]; //높이 세로선

void dfs(int x, int cur, int cnt) {
	if (cur == cnt) {
		bool flag = true;

		for (int i = 1; i <= n; i++) {
			int idx = i;
			for (int j = 1; j <= h; j++) {
				if (vis[j][idx]) idx++;
				else if (vis[j][idx - 1]) idx--;
			}
			if (idx != i) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << cnt;
			exit(0);
		}
		return;
	}

	for (int i = x; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (vis[i][j - 1] || vis[i][j] || vis[i][j + 1]) continue;
			vis[i][j] = true;
			dfs(i, cur + 1, cnt);
			vis[i][j] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;

	while (m--) {
		int a, b;
		cin >> a >> b;
		vis[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) { //정답이 3보다 크면 -1 (시작도 포함)
		dfs(1, 0, i);
	}

	cout << -1;
}
