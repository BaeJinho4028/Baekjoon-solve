#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, k;
bool vis[100005];
int cnt, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<pair<int,int>> q;
	q.push({ n, 0 });
	vis[n] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		vis[cur.X] = true;

		if (cur.X == k) {
			if (cur.Y == t)
				cnt++;
			if (cnt == 0) {
				cnt++;
				t = cur.Y;
			}
		}

		for (auto nxt : { cur.X - 1, cur.X + 1, 2 * cur.X }) {
			if (nxt < 0 || nxt >100000) continue;  
			if (vis[nxt]) continue;
			q.push({ nxt, cur.Y + 1 });
		}
	}
	cout << t << '\n' << cnt;
}