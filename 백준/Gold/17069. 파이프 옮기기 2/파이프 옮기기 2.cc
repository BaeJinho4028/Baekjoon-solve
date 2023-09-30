#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
const int INF = 1000000000;

int n;
int board[35][35];
ll d[35][35][3]; // 오른쪽, 아래, 대각선

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	d[1][2][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1)continue;
			if (board[i][j]) continue;

			if(board[i][j - 1] != 1)
				d[i][j][0] += d[i][j - 1][0] + d[i][j - 1][2];

			if (board[i - 1][j] != 1)
				d[i][j][1] += d[i - 1][j][1] + d[i - 1][j][2];

			if (board[i - 1][j] != 1 && board[i][j - 1] != 1)
				d[i][j][2] += d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
		}
	}

	cout << d[n][n][0] + d[n][n][1] + d[n][n][2];
}