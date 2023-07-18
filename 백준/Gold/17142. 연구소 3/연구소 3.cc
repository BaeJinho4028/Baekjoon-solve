#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m;
int board[50][50];
int dist[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> v;
bool vis[10];
int mx, mn = '????';
int e;

void bfs() {
	queue<pair<int, int>> q;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < v.size(); i++) {
		if (vis[i]) {
			q.push({ v[i].X, v[i].Y });
			dist[v[i].X][v[i].Y] = 0;
		}
	}

	int chk = 0;
	mx = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] != -1) continue;

			q.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (board[nx][ny] == 0) {
				mx = dist[nx][ny];
				chk++;
			}
		}
	}
	
	if (chk == e) mn = min(mn, mx);
}

void dfs(int cur, int idx) {
	if (cur == m) {
		bfs();
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		if (vis[i]) continue;
		vis[i] = true;
		dfs(cur + 1, i + 1);
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				e++;

			else if (board[i][j] == 2) 
				v.push_back({ i, j });
		}
	}

	dfs(0, 0);

	if (mn == '????') cout << -1;
	else cout << mn;
}