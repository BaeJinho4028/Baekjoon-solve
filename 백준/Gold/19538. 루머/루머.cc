#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int t[200005]; //루머 믿은 시간
queue<int> q, tq;
int n, m, Time;

int chk(int x) {
	int cnt = 0;
	for (auto nxt : adj[x]) {
		if (t[nxt] != -1) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		while (1) {
			int x;
			cin >> x;
			if (x == 0) break;
			adj[i].push_back(x);
		}
	}

	cin >> m;
	memset(t, -1, sizeof(t));
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		t[x] = 0;
		q.push(x);
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (t[nxt] != -1) continue;
			int rumor = chk(nxt); //주변에 루머 몇명인지
			if (rumor >= (adj[nxt].size() + 1) / 2) //절반이상 루머 믿으면
				tq.push(nxt);
		}

		if (q.empty()) {
			Time++;
			while (!tq.empty()) {
				auto tmp = tq.front(); tq.pop();
				t[tmp] = Time;
				q.push(tmp);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << t[i] << " ";
	}

}