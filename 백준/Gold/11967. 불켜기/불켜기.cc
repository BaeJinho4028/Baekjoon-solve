#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int,int>> board[105][105];
bool vis[105][105];
bool chk[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		board[x][y].push_back({ a, b });
	}

	int ans = 1;

	while (1) {
		bool flag = true;

		memset(vis, false, sizeof(vis));
		queue<pair<int, int>> q;
		chk[1][1] = true;
		q.push({ 1,1 });
		vis[1][1] = true;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (auto& l : board[cur.X][cur.Y]) {
				if (!chk[l.X][l.Y]) ans++;
				chk[l.X][l.Y] = true;
				flag = false;
			}
			board[cur.X][cur.Y].clear();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 1 || nx >n || ny<1 || ny>n) continue;
				if (!chk[nx][ny] || vis[nx][ny]) continue;
				q.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}
		if (flag) break;
	}

	cout << ans;
}