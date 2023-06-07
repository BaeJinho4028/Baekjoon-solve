#include <bits/stdc++.h>
using namespace std;

int board[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				board[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (board[i][j] == 0) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny >100 || ny < 0 || ny > 100) continue;
					if (board[nx][ny] == 0) continue;
					ans++;
				}
			}
		}
	}

	cout << ans;
}