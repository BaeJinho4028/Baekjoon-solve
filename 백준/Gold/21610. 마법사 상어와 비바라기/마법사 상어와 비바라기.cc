#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[55][55];
int vis[55][55];
int n, m;
int dx[8] = { 0,-1,-1,-1,0,1,1,1};
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

queue<pair<int, int>> q;
int d, s, ans;

void move() { //이동 + 물1증가 + 구름 사라짐
	int tmp = q.size();
	while(tmp--) {
		auto cur = q.front(); q.pop();
		int nx = cur.X, ny = cur.Y;
		for (int i = 0; i < s; i++) {
			nx += dx[d - 1];
			ny += dy[d - 1];
			if (nx < 0) {
				nx = n-1;
			}
			if (nx >= n) {
				nx = 0;
			}
			if (ny < 0) {
				ny = n-1;
			}
			if (ny >= n) {
				ny = 0;
			}
		}
		q.push({ nx, ny });
	}

	memset(vis, false, sizeof(vis));

	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		board[cur.X][cur.Y]++;
		vis[cur.X][cur.Y] = true;
	}
}

void bug() { //한번에 처리 해야함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) continue;
			int chk = 0;
			for (int dir = 1; dir < 8; dir += 2) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] == 0) continue;
				chk++;
			}

			board[i][j] += chk;
		}
	}
}

void cloud() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			if (board[i][j] < 2) continue;
			q.push({ i,j });
			board[i][j] -= 2;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	q.push({ n - 1,0 });
	q.push({ n - 1,1 });
	q.push({ n - 2,0 });
	q.push({ n - 2,1 });

	while (m--) {
		cin >> d >> s;

		move();
		bug();
		cloud();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += board[i][j];
		}
	}

	cout << ans;
}