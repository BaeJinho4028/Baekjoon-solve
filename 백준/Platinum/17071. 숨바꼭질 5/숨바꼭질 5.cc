#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, k;
int vis[500005][2];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	q.push({ n, 0 });
	vis[n][0] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		int pos = k + cur.Y * (cur.Y + 1) / 2;

		if (pos > 500000) {
			cout << -1;
			break;
		}
		if (cur.X == pos || vis[pos][cur.Y % 2]) {
			cout << cur.Y;
			break;
		}

		for (int nx : {cur.X - 1, cur.X + 1, cur.X * 2}) {
			if (nx < 0 || nx>500000 || vis[nx][(cur.Y + 1) % 2]) continue;
			q.push({ nx, cur.Y + 1 });
			vis[nx][(cur.Y + 1) % 2] = true;
		}
	}
}