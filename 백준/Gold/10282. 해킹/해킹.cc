#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pii pair<int,int>
int tc, n, d, c;
int vis[10005];
vector<pii> edge[10005];
int ans1, ans2;

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, c }); //시간, 컴퓨터
	vis[c] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		for (auto nxt : edge[cur.Y]) {
			if (vis[nxt.Y] > vis[cur.Y] + nxt.X) {
				vis[nxt.Y] = vis[cur.Y] + nxt.X;
				pq.push({ vis[nxt.Y], nxt.Y });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] != '????') {
			ans1++;
			ans2 = max(ans2, vis[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> d >> c;

		for (int i = 0; i < 10005; i++) {
			edge[i].clear();
		}
		ans1 = ans2 = 0;

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			edge[b].push_back({ s, a });
		}

		memset(vis, '????', sizeof(vis));
		dijkstra();

		cout << ans1 << ' ' << ans2 << '\n';
	}
}