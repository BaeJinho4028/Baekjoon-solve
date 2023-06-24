#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[9][9];
vector<pair<int, int>> v;
int n;
bool flag;

bool chk(int x, int y, int idx) {
	for (int i = 0; i < 9; i++) {
		if (board[i][y] == idx + '0') return false; //가로
		if (board[x][i] == idx + '0') return false; //세로
	}

	int nx = (x / 3) * 3;
	int ny = (y / 3) * 3;
	for (int i = nx; i < nx + 3; i++) {
		for (int j = ny; j < ny + 3; j++) {
			if (board[i][j] == idx + '0') return false; // 9등븐
		}
	}

	return true;
}

void solve(int cur) {
	if (flag) return;
	if (cur == n) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}

		flag = true;
		return;
	}

	int nx = v[cur].X;
	int ny = v[cur].Y;
	for (int i = 1; i <= 9; i++) {
		if (chk(nx, ny, i)) {
			board[nx][ny] = i + '0';
			solve(cur + 1);
			board[nx][ny] = '0';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0')
				v.push_back({ i,j });
		}
	}

	n = v.size();
	solve(0);
}