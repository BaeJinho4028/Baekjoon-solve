#include <bits/stdc++.h>
using namespace std;

int board[105][105] ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1, x2, y1, y2;
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				board[j][k] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			ans += board[i][j];
		}
	}

	cout << ans;
	
}