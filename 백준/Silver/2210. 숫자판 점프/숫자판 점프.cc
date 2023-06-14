#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[5][5];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[1000005];
int n, m;

void dfs(int num, int cur, int x, int y) {
	if (cur == 6) {
		if (vis[num]) return;
		vis[num] = true;
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		dfs(num * 10 + board[nx][ny], cur + 1, nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(0, 0, i, j);

	int cnt = 0;
	for (int i = 0; i <= 1000000; i++)
		if (vis[i]) cnt++;

	cout << cnt;
}