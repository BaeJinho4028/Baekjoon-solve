#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<pair<int, int>> e[100005];
bool vis[100005];
ll mx, node;

void dfs(int x, ll sum) {
	if (vis[x]) return;
	vis[x] = true;

	if (sum > mx) {
		mx = sum;
		node = x;
	}

	for (auto nxt : e[x]) {
		dfs(nxt.X, sum + nxt.Y);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> v;

	for (int i = 0; i < v; i++) {
		int a, b, c;
		cin >> a;

		cin >> b;
		while (b != -1) {
			cin >> c;

			e[a].push_back({ b, c });

			cin >> b;
		}
	}

	dfs(1, 0);

	memset(vis, false, sizeof(vis));
	mx = 0;

	dfs(node, 0);

	cout << mx;
}
