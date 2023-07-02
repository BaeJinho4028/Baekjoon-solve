#include <bits/stdc++.h>
using namespace std;

/*
1. 구역 2곳으로 나누기 (1 ~ n/2)  : 백트래킹
2. 고른곳들 유니온파인드로 연결
3. 구역 bfs돌렸는데 모두 체크됐으면 인구수 빼기
*/

#define MAX 15
#define INF 0x7f7f7f7f

int po[MAX], p[MAX];
bool vis[MAX], chk[MAX];
int n, ans = INF;
vector<int> adj[MAX];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u < v) p[v] = u;
	else p[u] = v;
}

bool bfs(vector<int>& v) {
	memset(chk, false, sizeof(chk));

	queue<int> q;
	q.push(v[0]);
	chk[v[0]] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (chk[nxt] || p[nxt] != p[cur]) continue;
			chk[nxt] = true;
			q.push(nxt);
		}
	}

	for (auto x : v) if (!chk[x]) return false;
	return true;
}

void dfs(int cur, int idx, int r) {
	if (cur == r) {
		for (int i = 1; i <= n; i++) p[i] = i;
		vector<int> A, B;
		int a = 0, b = 0;

		for (int i = 1; i <= n; i++) {
			if (vis[i]) A.push_back(i), a += po[i];
			else B.push_back(i), b += po[i];
		}

		for (int i = 1; i < A.size(); i++) 
			merge(A[i - 1], A[i]);
		for (int i = 1; i < B.size(); i++)
			merge(B[i - 1], B[i]);

		if (bfs(A) && bfs(B)) ans = min(ans, abs(a - b));
		return;
	}

	for (int i = idx; i <= n; i++) {
		vis[i] = true;
		dfs(cur + 1, i + 1, r);
		vis[i] = false;
	}
}


int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> po[i];
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x--) {
			int u;
			cin >> u;
			adj[u].push_back(i);
			adj[i].push_back(u);
		}
	}

	for (int i = 1; i <= n / 2; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(0, 1, i);
	}

	if (ans == INF) cout << -1;
	else cout << ans;
}