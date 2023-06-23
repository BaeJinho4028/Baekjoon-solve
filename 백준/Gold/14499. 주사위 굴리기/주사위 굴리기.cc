#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[25][25];
vector<pair<int, int>> v;
int n, m, x, y, k;
int dx[4] = { 0,0,-1,1 }; //동서북남
int dy[4] = { 1,-1,0,0 };

vector<int> dice(6); // 0위  1동 2서 3남 4북 5아래

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int d;
	while (k--) {
		cin >> d;

		int nx = x + dx[d - 1];
		int ny = y + dy[d - 1];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		x = nx;
		y = ny;

		//주사위 돌리기
		if (d - 1 == 0) //동
			dice = {dice[2], dice[0], dice[5], dice[3] ,dice[4], dice[1] };
		if (d - 1 == 1) //서
			dice = { dice[1], dice[5], dice[0], dice[3] ,dice[4], dice[2] };
		if (d - 1 == 2) //북
			dice = { dice[3], dice[1], dice[2], dice[5] ,dice[0], dice[4] };
		if (d - 1 == 3) //남
			dice = { dice[4], dice[1], dice[2], dice[0] ,dice[5], dice[3] };




		cout << dice[0] << '\n';

		if (board[x][y] == 0)
			board[x][y] = dice[5];
		else {
			dice[5] = board[x][y];
			board[x][y] = 0;
		}
	}
}