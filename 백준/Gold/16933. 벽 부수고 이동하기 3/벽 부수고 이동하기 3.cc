#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
char board[1005][1005];
bool vis[1005][1005][10];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	queue<tuple<int,int,int,int,bool>> q;
	q.push({1,1,0,1,true});
	vis[1][1][0] = true;

	int ans = -1;
	while (!q.empty()) {
		auto [x,y,z,cnt,sun] = q.front(); q.pop();
		if (x == n && y == m) {
			ans = cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx<1 || nx >n || ny<1 || ny > m) continue;

			if (board[nx][ny] == '0') {
				if (!vis[nx][ny][z]) {
					vis[nx][ny][z] = true;
					q.push({ nx,ny,z,cnt+1,!sun });
				}
			}
			if (board[nx][ny] == '1') {
				if (z < k) {
					if (sun) {
						if (!vis[nx][ny][z+1]) {
							vis[nx][ny][z + 1] = true;
							q.push({ nx,ny,z + 1,cnt + 1,!sun });
						}
					}
					else {
						q.push({ x,y,z,cnt+1,!sun });
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}