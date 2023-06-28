#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[500005];
bool vis[500005];
int cnt;

//리프노드에서 루트노드까지 짝수이냐 홀수이냐 (깊이의 총합이 홀짝)

void dfs(int x, int dep) {
	if (x != 1 && adj[x].size() == 1) { // 리프노드일경우
		cnt += dep;
		return;
	}
	
	for (auto a : adj[x]) {
		if (vis[a]) continue;
		vis[a] = true;
		dfs(a, dep + 1);
		vis[a] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vis[1] = true;
	dfs(1, 0);


	if (cnt % 2 == 0) cout << "No";
	else cout << "Yes"; //홀수면 성원이가 이김
}