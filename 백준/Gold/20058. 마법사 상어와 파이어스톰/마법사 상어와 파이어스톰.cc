#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int a[1 << 6][1 << 6];
int tmp[1 << 6][1 << 6];
bool vis[1 << 6][1 << 6];

int n, m, l;
int sum, ans;

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x , y });
	vis[x][y] = true;

	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (a[nx][ny] == 0 || vis[nx][ny]) continue;
			q.push({nx, ny});
			vis[nx][ny] = true;
		}
	}
	return cnt;
}

void ice() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			tmp[i][j] = a[i][j];
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (a[nx][ny] == 0) continue;
				cnt++;
			}
			if (cnt < 3) tmp[i][j] = max(--tmp[i][j], 0);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

void rotate(int x, int y, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			tmp[i][j] = a[x + h - j - 1][y + i];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) {
			a[x + i][y + j] = tmp[i][j];
		}
	}
}

void devide(int h) {
	for (int i = 0; i < n; i += h) {
		for (int j = 0; j < n; j += h) {
			rotate(i, j, h);
		}
	}

	ice();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	n = 1 << n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	while (m--) {
		cin >> l;
		devide(1 << l);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(a[i][j]) ans = max(ans, bfs(i, j));
		}
	}

	cout << sum << '\n' << ans;
}