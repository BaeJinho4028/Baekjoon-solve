#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[130][130];
int dist[130][130];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=1;;i++) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				dist[i][j] = 0x7f7f7f7f;
			}
		}

		priority_queue<pair<int, pair<int,int>>> pq;
		pq.push({ -1 * board[0][0], {0, 0} });
		dist[0][0] = board[0][0];

		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.Y.X + dx[dir];
				int ny = cur.Y.Y + dy[dir];
				
				if (nx < 0 || nx >= n || ny < 0 || nx >= n) continue;
				
				int nc = board[nx][ny];

				if (dist[nx][ny] > dist[cur.Y.X][cur.Y.Y] + nc) {
					dist[nx][ny] = dist[cur.Y.X][cur.Y.Y] + nc;
					pq.push({ -1 * dist[cur.Y.X][cur.Y.Y] + nc, {nx, ny} });
				}
			}
		}

		cout << "Problem " << i << ": " << dist[n - 1][n - 1] << "\n";
	}
}