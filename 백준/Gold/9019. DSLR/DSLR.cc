#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool vis[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		memset(vis, false, sizeof(vis));

		queue<pair<int, string>> q;
		q.push({ a, "" });
		vis[a] = true;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			if (cur.X == b) {
				cout << cur.Y << '\n';
				break;
			}

			int d = (cur.X * 2) % 10000;
			if (!vis[d]) {
				vis[d] = true;
				q.push({ d, cur.Y + "D" });
			}

			int s = cur.X-1 >= 0 ? cur.X - 1 : 9999;
			if (!vis[s]) {
				vis[s] = true;
				q.push({ s, cur.Y + "S" });
			}

			int l = (cur.X % 1000) * 10 + (cur.X / 1000);
			if (!vis[l]) {
				vis[l] = true;
				q.push({ l, cur.Y + "L" });
			}

			int r = (cur.X%10) * 1000 + (cur.X/10);
			if (!vis[r]) {
				vis[r] = true;
				q.push({ r, cur.Y + "R" });
			}
		}
	}
	
}