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
ll mx, mn = '????';

char board[605][605];
bool vis[605][605];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'I') x = i, y = j;
		}
	}

	queue<pii> q;
	q.push({ x, y });
	vis[x][y] = true;

	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {

			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'X' || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			q.push({ nx, ny });
			if (board[nx][ny] == 'P') cnt++;
		}
	}

	if (cnt != 0) cout << cnt;
	else cout << "TT";
}