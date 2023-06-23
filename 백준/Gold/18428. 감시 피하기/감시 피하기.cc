#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> t,e;//선생님, 빈공간
bool flag;
int n;

bool chk(int x, int y) {//감시 걸리는지 안걸리는지
	for (int dir = 0; dir < 4; dir++) {
		int nx = x;
		int ny = y;
		while (1) {
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
			if (board[nx][ny] == 'O') break;
			if (board[nx][ny] == 'S') return true; //걸림ㅠ
			nx += dx[dir];
			ny += dy[dir];
		}
	}
	return false;
}

void solve(int cur, int idx) {
	if (cur == 3) {
		for (auto a : t) {
			if (chk(a.X, a.Y)) {
				return;
			}
		}
		flag = true;
		return;
	}

	for (int i = idx; i < e.size(); i++) {
		board[e[i].X][e[i].Y] = 'O';
		solve(cur + 1, i + 1);
		board[e[i].X][e[i].Y] = 'X';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'T')
				t.push_back({ i, j });
			if (board[i][j] == 'X') 
				e.push_back({ i,j });
		}
	}

	solve(0, 0);

	if (flag) cout << "YES";
	else cout << "NO";
}