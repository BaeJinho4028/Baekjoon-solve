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

int board[255][255];
bool vis[255][255];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	queue<pii> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) q.push({ i, j }), vis[i][j] = true, cnt++;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 8; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] != 1 || vis[nx][ny]) continue;

					q.push({ nx,ny });
					vis[nx][ny] = true;
					board[nx][ny] = cnt;
				}
			}
		}
	}



	cout << cnt;
}