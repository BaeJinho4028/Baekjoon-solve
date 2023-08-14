#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[105][105];
int a, b, n, m;
int dx[4] = { 0,-1,0,1 }; //서북동남
int dy[4] = { -1, 0,1,0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> n >> m;

	vector<pair<pair<int, int>, int>> v;
	v.push_back({ { 0,0 }, 0 });
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		char c;
		cin >> x >> y >> c;

		if (c == 'W') z = 0;
		else if (c == 'N') z = 1;
		else if (c == 'E') z = 2;
		else if (c == 'S') z = 3;

		v.push_back({ {b - y + 1, x}, z });
		board[b - y + 1][x] = i;
	}

	while (m--) {
		int r, t;
		char c;
		cin >> r >> c >> t;

		while (t--) {
			if (c == 'L') v[r].Y = (v[r].Y + 3) % 4;
			else if (c == 'R') v[r].Y = (v[r].Y + 1) % 4;
			else if (c == 'F') {
				int nx = v[r].X.X + dx[v[r].Y];
				int ny = v[r].X.Y + dy[v[r].Y];

				if (nx < 1 || nx > b || ny < 1 || ny > a) {
					cout << "Robot " << r << " crashes into the wall";
					return 0;
				}
				if (board[nx][ny] != 0) {
					cout << "Robot " << r << " crashes into robot " << board[nx][ny];
					return 0;
				}
				board[nx][ny] = r;
				board[v[r].X.X][v[r].X.Y] = 0;
				v[r].X.X = nx;
				v[r].X.Y = ny;
			}
		}
	}

	cout << "OK";
}