#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int board[15][15];
vector<int> h[15][15];
pair<pair<int, int>, int > horse[15];
int n, k;

int turn(int d) {
	if (d == 1) return 2;
	if (d == 2) return 1;
	if (d == 3) return 4;
	if (d == 4) return 3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= k; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		horse[i] = { {x,y}, d };
		h[x][y].push_back(i);
	}

	for (int t = 1; t <= 1000; t++) {
		for (int kk = 1; kk <= k; kk++) {

			int x = horse[kk].X.X;
			int y = horse[kk].X.Y;
			int dir = horse[kk].Y;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 2) {
				horse[kk].Y = dir = turn(dir);
				

				nx = x + dx[dir];
				ny = y + dy[dir];

				if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 2)
					continue;
			}

			vector<int>& cur = h[x][y];
			vector<int>& nxt = h[nx][ny];

			auto s = find(cur.begin(), cur.end(), kk);

			if (board[nx][ny] == 1)
				reverse(s, cur.end());

			for (auto it = s; it != cur.end(); it++) {
				horse[*it].X.X = nx;
				horse[*it].X.Y = ny;

				nxt.push_back(*it);
			}
			cur.erase(s, cur.end());


			if (h[nx][ny].size() >= 4) {
				cout << t;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}