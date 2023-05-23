#include <bits/stdc++.h>
using namespace std;

int board[55][55];
int dx[4] = { -1, 0, 1, 0 }; //북, 동, 남, 서
int dy[4] = { 0, 1, 0, -1 };

int x, y, d, n, m, cnt;

bool chk() {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == 1) continue;
		if (board[nx][ny] == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		if (board[x][y] == 0) cnt++;
		board[x][y] = 2;
		if (chk()) { // 4칸 청소다됨 >> 후진
			int nx = x + dx[(d + 2) % 4];
			int ny = y + dy[(d + 2) % 4];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) break; //뒤가 막힘
			if (board[nx][ny] == 1) break;
			x = nx;
			y = ny;
			continue;
		}
		else { //4칸 청소 안됨
			while (1) {
				d = (d + 3) % 4; //반시계 90도 회전
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 1) continue;
				if (board[nx][ny] == 0) {// 전진
					x = nx;
					y = ny;
					break;
				}
			}
		}
	}

	cout << cnt;
}