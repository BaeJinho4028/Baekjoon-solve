#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int h, w;
char board[105][105];
bool vis[105][105];
bool az[26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		memset(board, '.', sizeof(board));
		memset(vis, false, sizeof(vis));
		memset(az, false, sizeof(az));
		vis[0][0] = true;
		int cnt = 0;

		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> board[i][j];
			}
		}
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') break;
			az[s[i] - 'a'] = true;
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx <0 || nx>h+1 || ny<0 || ny >w+1) continue;
				if (board[nx][ny] == '*' || vis[nx][ny]) continue;
				if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z')
					if (!az[board[nx][ny] - 'A']) continue;

				if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z' && !az[board[nx][ny] - 'a']) {
					az[board[nx][ny] - 'a'] = true;
					while (!q.empty()) {
						q.pop();
					}
					memset(vis, false, sizeof(vis));
				}

				if (board[nx][ny] == '$') {
					board[nx][ny] = '.';
					cnt++;
				}

				q.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}
		cout << cnt << '\n';
	}
}