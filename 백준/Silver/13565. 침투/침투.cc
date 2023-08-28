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

char board[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	memset(board, '0', sizeof(board));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pii> q;
	q.push({ 0,1 });
	board[0][1] = '2';

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx<0 || nx>n || ny <1 || ny >m) continue;
			if (board[nx][ny] != '0') continue;
			board[nx][ny] = '2';
			q.push({ nx, ny });
		}
	}

	bool flag = true;
	for (int j = 1; j <= m; j++) {
		if (board[n][j] == '2') flag = false;
	}
	if (!flag) cout << "YES";
	else cout << "NO";
}