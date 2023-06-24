#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[55][55];
int add[55][55];
int r, c, t, ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int x1, x2;

void dust() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] <= 0) continue;
			int cnt = 0, tmp = board[i][j] / 5;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (board[nx][ny] == -1) continue;
				add[nx][ny] += tmp;
				cnt++;
			}
			board[i][j] -= (cnt * tmp);
		}
	}

	for (int i = 0; i < r; i++) { //더하기
		for (int j = 0; j < c; j++) {
			board[i][j] += add[i][j];
			add[i][j] = 0;
		}
	}
}

void cleaner() {
	//공기청정기 먼지 사라짐
	ans -= board[x1 - 1][0];
	ans -= board[x2 + 1][0];

	//공기청정기 위쪽 (반시계)
	for (int i = x1 -1; i > 0; i--) //왼쪽줄 
		board[i][0] = board[i - 1][0];
	for (int i = 0; i < c - 1; i++) //윗쪽줄
		board[0][i] = board[0][i+1];
	for (int i = 0; i < x1; i++) //오른쪽줄 
		board[i][c-1] = board[i + 1][c-1];
	for (int i = c - 1; i > 0; i--) //아래쪽줄
		board[x1][i] = board[x1][i-1];
	board[x1][1] = 0; //공기청정기에서 나가는 공기

		//공기청정기 아래쪽 (반시계)
	for (int i = x2 + 1; i < r-1; i++) //왼쪽줄 
		board[i][0] = board[i + 1][0];
	for (int i = 0; i < c - 1; i++) //윗쪽줄
		board[r-1][i] = board[r-1][i + 1];
	for (int i = r-1; i > x1; i--) //오른쪽줄 
		board[i][c - 1] = board[i - 1][c - 1];
	for (int i = c - 1; i > 0; i--) //아래쪽줄
		board[x2][i] = board[x2][i - 1];
	board[x2][1] = 0; //공기청정기에서 나가는 공기
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				x2 = i;
			}
			else ans += board[i][j];
		}
	}
	x1 = x2 - 1;

	while (t--) {
		dust();
		cleaner();
	}

	cout << ans << '\n';
}