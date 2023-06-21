#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int cnt[10];
char board[2515][2515];

bool chk() {
	for (int i = 0; i < 10; i++) {
		if (cnt[i] != 1)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '1') v.push_back({ i,j });
		}
	}

	int ansx = -1, ansy = -1;

	for (auto cur : v) {
		int x = cur.X;
		int y = cur.Y;

		memset(cnt, 0, sizeof(cnt));

		for (int i = x - 9; i < x + 10; i++) {
			for (int j = y - 9; j < y + 10; j++) {
				if (i < 0 || i >= n || j < 0 || j >= m) continue;
				if (board[i][j] == '0') continue;
				cnt[max(abs(x - i), abs(y - j))]++;
			}
		}
		if (chk()) {
			cout << x << ' ' << y;
			return 0;
		}
	}

	cout << -1;
}