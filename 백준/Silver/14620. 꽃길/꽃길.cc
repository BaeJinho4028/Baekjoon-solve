#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
int dx[8] = { 1,0,-1,0 };
int dy[8] = { 0,1,0,-1 };
int n, m;
int mx, mn = '????';

int board[15][15];
bool vis[15][15];

void dfs(int cur, int val) {
	if (cur == 3) {
		mn = min(mn, val);
		return;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 2; j < n; j++) {
			bool flag = false;
			for (int dir = 0; dir < 5; dir++) {
				if (vis[i + dx[dir]][j + dy[dir]]) {
					flag = true;
					break;
				}
			}
			if (flag) continue;

			int tmp = 0;
			for (int dir = 0; dir < 5; dir++) {
				vis[i + dx[dir]][j + dy[dir]] = true;
				tmp += board[i + dx[dir]][j + dy[dir]];
			}
			dfs(cur + 1, val + tmp);
			for (int dir = 0; dir < 5; dir++) {
				vis[i + dx[dir]][j + dy[dir]] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0);

	cout << mn;
}