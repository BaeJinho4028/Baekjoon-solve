#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[25][25];
int st[405][4];
int n;

/*
1. 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
2. 1을 만족하는 칸이 여러 개면, 인접한 칸 중 비어있는 칸이 가장 많은 칸으로 자리 정한다.
3. 2를 만족하는 칸도 여러 개인 경우 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개면 열의 번호가 가장 작은 칸으로.
*/

bool islike(int cur, int x, int y) { //주변에 좋아하는 사람 있는지
	for (int i = 0; i < 4; i++) {
		if (st[cur][i] == board[x][y]) return true;
	}
	return false;
}

void sit(int cur) {
	int rx = -1, ry = -1; //앉을 위치
	int mxst = -1, mxe = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int likest = 0; // 좋아하는 학생 수
			int empty = 0; //빈자리

			if (board[i][j] > 0) continue;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

				if (board[nx][ny] == 0) empty++;
				else if (islike(cur, nx, ny)) likest++;
			}

			if (likest > mxst) { //1
				mxst = likest;
				mxe = empty;
				rx = i;
				ry = j;
			}
			else if(likest == mxst) { // 2
				if (empty > mxe) {
					mxe = empty;
					rx = i;
					ry = j;
				}
				else if (empty == mxe) { // 3
					if (rx == i && ry > j) 
						ry = j;
					else if (rx > i) {
						rx = i;
						ry = j;
					}
				}
			}
		}
	}

	board[rx][ry] = cur;
}

int solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			int f = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (islike(board[i][j], nx, ny)) 
					f++;
			}

			if (f == 1) 
				ans += 1;
			else if (f == 2) 
				ans += 10;
			else if (f == 3) 
				ans += 100;
			else if (f == 4) 
				ans += 1000;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n * n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < 4; j++)
			cin >> st[x][j];

		sit(x);
	}

	cout << solve();
}