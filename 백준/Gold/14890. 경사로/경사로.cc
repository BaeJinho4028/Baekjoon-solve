#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[105][105];
int ans;

/*
정리습관

1. 경사로 겹치면 안됨
2. 올라가는경우 연속된층 L만큼있었는지
3. 내려가는경우 연속된층이 L만큼 있을지
*/

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		bool flag = true;
		int cnt = 1;
		
		for (int j = 1; j < n; j++) {
			if (board[i][j - 1] == board[i][j]) cnt++;
			else if (board[i][j - 1] - board[i][j] == -1 && cnt >= l) cnt = 1;
			else if (board[i][j - 1] - board[i][j] == 1 && cnt >= 0) cnt = -l + 1;
			else flag = false;
		}

		if (flag && cnt >= 0) ans++;
	}

	for (int i = 0; i < n; i++) {
		bool flag = true;
		int cnt = 1;

		for (int j = 1; j < n; j++) {
			if (board[j-1][i] == board[j][i]) cnt++;
			else if (board[j-1][i] - board[j][i] == -1 && cnt >= l) cnt = 1;
			else if (board[j-1][i] - board[j][i] == 1 && cnt >= 0) cnt = -l + 1;
			else flag = false;
		}

		if (flag && cnt >= 0) ans++;
	}

	cout << ans;
}
