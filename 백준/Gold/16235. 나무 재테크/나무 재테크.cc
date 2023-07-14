#include <bits/stdc++.h>
using namespace std;

int board[15][15];
int a[15][15];
vector<int> tree[15][15];
int n, m, k;

int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

void springsummer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;

			int die = 0;
			vector<int> tmp;
			sort(tree[i][j].begin(), tree[i][j].end());

			for (auto age : tree[i][j]) {
				if (board[i][j] >= age) {
					board[i][j] -= age;
					tmp.push_back(age + 1);
				}
				else die += age / 2;
			}
			
			tree[i][j].clear();
			for (auto x : tmp)
				tree[i][j].push_back(x);

			board[i][j] += die;
		}
	}
}

void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;

			for (auto age : tree[i][j]) {
				if (age % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (nx<1 || nx>n || ny < 1 || ny > n) continue;

						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j] += a[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			board[i][j] = 5;
		}
	}

	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;

		tree[x][y].push_back(z);
	}

	while (k--) {
		springsummer();
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += tree[i][j].size();
		}
	}

	cout << ans;
}