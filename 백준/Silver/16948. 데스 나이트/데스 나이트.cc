#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[205][205];
int dist[205][205];
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	memset(dist, -1, sizeof(dist));

	queue<pair<int, int>> q;
	q.push({ r1, c1 });

	dist[r1][c1] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	cout << dist[r2][c2];
}