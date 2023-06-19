#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[205][205];
bool vis[205][205];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c, n;

void pr() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> n;
	
	int cnt = 0;

	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'O') q.push({ i,j });
		}
	}

	if (n == cnt++) {
		pr();
		return 0;
	}

	if (n == cnt++) {
		pr();
		return 0;
	}

	while (1) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == '.') board[i][j] = 'O';
			}
		}

		if (n == cnt++) {
			pr();
			return 0;
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				board[cur.X][cur.Y] = '.';
				board[nx][ny] = '.';
			}
		}

		if (n == cnt++) {
			pr();
			return 0;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == 'O') q.push({ i,j });
			}
		}
	}
}