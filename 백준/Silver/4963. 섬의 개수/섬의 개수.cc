#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[55][55];
bool vis[55][55];
int dx[8] = { 1,0,-1,0, 1, 1, -1 ,-1 };
int dy[8] = { 0,1,0,-1 ,1,-1,1,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int w, h;
	while (cin >> w >> h) {
		if (w == 0 && h == 0) return 0;
	
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				vis[i][j] = 0;
			}
		}

		int ans = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;

				queue<pair<int, int>> q;
				ans++;
				q.push({ i, j });
				vis[i][j] = 1;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 8; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
						if (board[nx][ny] == 0 || vis[nx][ny]) continue;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}