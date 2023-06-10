#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int dx[8] = { 0,0,1,-1,-1,-1,1,1};
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char a, b;
	int c, d, n;

	cin >> a >> c >> b >> d >> n;

	int x = 8 - c, y = a - 'A';
	int sx = 8 - d, sy = b - 'A';
	while (n--) {
		string s;
		cin >> s;

		int dir;
		if (s == "R") dir = 0;
		else if(s == "L") dir = 1;
		else if (s == "B") dir = 2;
		else if (s == "T") dir = 3;
		else if (s == "RT") dir = 4;
		else if (s == "LT") dir = 5;
		else if (s == "RB") dir = 6;
		else if (s == "LB") dir = 7;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >7 || ny < 0 || ny >7) continue;

		if (nx == sx && ny == sy) {
			int nsx = sx + dx[dir];
			int nsy = sy + dy[dir];
			if (nsx < 0 || nsx >7 || nsy < 0 || nsy >7) continue;

			sx = nsx, sy = nsy;
		}
		x = nx, y = ny;
	}

	a = y + 'A';
	b = sy + 'A';

	cout << a << 8 - x << '\n';
	cout << b << 8 - sx;
}