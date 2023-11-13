#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n, m, k;
int board[55][55];
int tmp[55][55];
bool vis[10];
int op[10];
int mn = '????';
vector <pair<pair<int, int>, int>> v;

void rotate(int x, int y, int z) {
	for (int s = 1; s <= z; s++) {
		int t = tmp[x - s][y - s];
		for (int i = x - s; i < x + s; i++) //왼
			tmp[i][y - s] = tmp[i + 1][y - s];
		for (int i = y - s; i < y + s; i++) // 아래
			tmp[x + s][i] = tmp[x + s][i + 1];
		for (int i = x + s; i > x - s; i--) //오
			tmp[i][y + s] = tmp[i - 1][y + s];
		for (int i = y + s; i > y - s; i--)//위
			tmp[x - s][i] = tmp[x - s][i - 1];
		tmp[x - s][y - s + 1] = t;
	}
}

void bt(int cur) {
	if (cur == k) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				tmp[i][j] = board[i][j];
			}
		}
		for (int i = 0; i < k; i++) {
			rotate(v[op[i]].X.X, v[op[i]].X.Y, v[op[i]].Y);
		}

		for (int i = 1; i <= n; i++) {
			int chk = 0;
			for (int j = 1; j <= m; j++) {
				chk += tmp[i][j];
			}
			mn = min(mn, chk);
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		op[cur] = i;
		bt(cur + 1);
		vis[i] = false;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ {r, c}, s });
	}

	bt(0);

	cout << mn;
}
