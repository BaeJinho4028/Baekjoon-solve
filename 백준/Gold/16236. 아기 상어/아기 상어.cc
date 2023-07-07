#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[25][25];
int dist[25][25];
int dx[4] = { -1,0,0,1 };  //위 왼 오 아래
int dy[4] = { 0,-1,1,0 };
int x, y, z= 2, cnt; // 상어 몇개먹었는지
int n, t;

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ x, y });
	dist[x][y] = 0;

	int fx = 100, fy = 100, ft = 500;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] > z || dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (board[nx][ny] == 0 || board[nx][ny] == z) q.push({ nx, ny });
			else if (board[nx][ny] < z && ft >= dist[nx][ny]) {
				if (nx < fx || (nx == fx && ny < fy)) {
					fx = nx;
					fy = ny;
					ft = dist[nx][ny];
				}
			}
		}
	}



	if (fx == 100 && fy == 100) return false;
	else {

		//cout << fx << ' ' << fy << ' ' << ft << '\n';
		x = fx;
		y = fy;
		board[fx][fy] = 0;
		t += ft;

		return true;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				x = i, y = j;
				board[x][y] = 0;
			}
		}
	}

	while(1) {
		memset(dist, -1, sizeof(dist));
		if (bfs()) {
			board[x][y] = 0;
			cnt++;
			if (cnt == z) {
				cnt = 0;
				z++;
			}
			continue;
		}
		else break;
	}

	cout << t;
}
