#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a, b, c;
bool vis[1505][1505];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	int sum = a + b + c;

	if (sum % 3 != 0) {
		cout << "0";
		return 0;
	}

	queue<pair<int, int>> q;
	q.push({ a, b });
	vis[a][b] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		int tmp[3] = { cur.X, cur.Y, sum - cur.X - cur.Y };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tmp[i] < tmp[j]) {
					int nx = tmp[i] * 2;
					int ny = tmp[j] - tmp[i];
					if (vis[nx][ny]) continue;

					vis[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}

	cout << vis[sum / 3][sum / 3];
}