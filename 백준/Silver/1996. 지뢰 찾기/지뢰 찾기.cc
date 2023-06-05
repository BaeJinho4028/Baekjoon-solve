#include <bits/stdc++.h>
using namespace std;

int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
char s[1005][1005];
char board[1005][1005] ;

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] != '.') {
				board[i][j] = '*';
				continue;
			}

			int cnt = 0;
			for (int dir = 0; dir < 8; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (s[nx][ny] == '.') continue;
				cnt += s[nx][ny] - '0';
			}

			if (cnt >= 10) board[i][j] = 'M';
			else board[i][j] = cnt + '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}