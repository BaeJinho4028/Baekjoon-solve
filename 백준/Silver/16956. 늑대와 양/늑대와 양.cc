#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[505][505];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') q.push({ i, j });
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'W') flag = true;
			if (board[nx][ny] != '.') continue;
			board[nx][ny] = 'D';
		}
	}

	if (flag) {
		cout << 0;
		return 0;
	}
	else {
		cout << 1 << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
	}
}