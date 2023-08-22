#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003

int board[15][15];
int ans = '????';
int paper[7];

bool chk(int x, int y, int p) {
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			if (board[x + i][y + j] == 0)
				return false;
		}
	}
	return true;
}

void dfs(int cnt, int x, int y) {

	bool flag = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 1) {
				x = i;
				y = j;
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	if (flag) ans = min(ans, cnt);

	if (cnt >= ans) return;


	for (int i = 5; i >= 1; i--) {
		if (x + i > 10 || y + i > 10) continue;
		if (paper[i] >= 5) continue;
		if (!chk(x, y, i)) continue;

		paper[i]++;
		for (int j = 0; j < i; j++) 
			for (int k = 0; k < i; k++) 
				board[x + j][y + k] = 0;
			
		dfs(cnt + 1, x, y);

		paper[i]--;
		for (int j = 0; j < i; j++)
			for (int k = 0; k < i; k++)
				board[x + j][y + k] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 0);

	if (ans == '????') cout << -1;
	else cout << ans;
}