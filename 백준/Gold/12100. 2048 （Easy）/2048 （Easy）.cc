#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
int r[22][22];

void rotate() {
	int tmp[22][22];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = board[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = tmp[n - 1 - j][i];
}

void up(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < n; i++) {
		int t[22] = {};
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;
			if (t[idx] == 0) t[idx] = board[i][j];
			else if (t[idx] == board[i][j])
				t[idx++] *= 2;
			else t[++idx] = board[i][j];
		}
		for (int j = 0; j < n; j++) board[i][j] = t[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> r[i][j];

	int mx = 0;

	for (int tmp = 0; tmp < (1 << (10)); tmp++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = r[i][j];
		int brute = tmp;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;
			up(dir);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mx = max(mx, board[i][j]);
	}
	cout << mx;
}