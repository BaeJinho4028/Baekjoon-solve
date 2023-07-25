#include <bits/stdc++.h>
using namespace std;

int n, p;
vector<int> adj[1000005];
int d[1000005][2]; //[해당노드]가 [0얼리어답터, 1일반인 일경우] : 얼리어답터 수
bool vis[1000005];

void dfs(int x) {
	vis[x] = true;
	d[x][0] = 1;

	for (auto nxt : adj[x]) {
		if (vis[nxt]) continue;
		dfs(nxt);
		d[x][0] += min(d[nxt][0], d[nxt][1]); 
		d[x][1] += d[nxt][0]; //부모가 일반인이면 자식은 얼리어답터여야함
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << min(d[1][0], d[1][1]);
}