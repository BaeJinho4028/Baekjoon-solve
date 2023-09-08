#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };

int n;
vector<tiii> e;
vector<int> p(1050, -1);
vector<int> edge[1050];
int cnt;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool dif(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;

	p[u] = v;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			int c;
			cin >> c;
			e.push_back({ c, i, j });
		}
	}

	sort(e.begin(), e.end());

	//mst 작은순으로 넣으면 당연히 인접한 노드끼리 먼저 연결될듯?
	for (int i = 0; i < e.size(); i++) {
		int a, b, c;
		tie(c, a, b) = e[i];
		if (!dif(a, b)) continue;
		cnt++;
		edge[a].push_back(b);
		edge[b].push_back(a);

		if (cnt == n - 1) {
			for (int j = 1; j <= n; j++) {
				cout << edge[j].size() << ' ';
				sort(edge[j].begin(), edge[j].end());
				for (auto x : edge[j]) {
					cout << x << ' ';
				}
				cout << '\n';
			}
		}
	}
}