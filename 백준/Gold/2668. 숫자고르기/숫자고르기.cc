#include <bits/stdc++.h>
using namespace std;

int a[105];
bool vis[105];
int mx;
vector<int> ans;

void dfs(int x,int st) {
	if (vis[x]) {
		if (x == st) {
			ans.push_back(st);
		}
	}
	else {
		vis[x] = true;
		dfs(a[x], st);
	}
}

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
	}

	cout << ans.size() << '\n';
	for (int v : ans) {
		cout << v << ' ';
	}
}
