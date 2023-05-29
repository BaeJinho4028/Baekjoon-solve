#include <bits/stdc++.h>
using namespace std;

int board[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j <= y2; j++) {
			for (int k = x1; k <= x2; k++) {
				board[j][k]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (board[i][j] > m) cnt++;
		}
	}

	cout << cnt;
}