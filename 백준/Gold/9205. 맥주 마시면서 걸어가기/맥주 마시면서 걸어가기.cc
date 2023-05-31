#include <bits/stdc++.h>
using namespace std;

struct point {
	int x;
	int y;
};

#define X first
#define Y second
point store[105];
point fest, home;
bool vis[105];
int n;

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ home.x, home.y });

	while (!q.empty()) {
		auto cur = q.front();  q.pop();
		
		if (abs(fest.x - cur.X) + abs(fest.y - cur.Y) <= 1000) return true;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			if (abs(store[i].x - cur.X) + abs(store[i].y - cur.Y) <= 1000) {
				vis[i] = true;
				q.push({ store[i].x, store[i].y });
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		cin >> home.x >> home.y;
		for (int i = 0; i < n; i++) {
			cin >> store[i].x >> store[i].y;
		}
		cin >> fest.x >> fest.y;

		memset(vis, 0, sizeof(vis));

		if (bfs()) cout << "happy\n";
		else cout << "sad\n";
	}
}
