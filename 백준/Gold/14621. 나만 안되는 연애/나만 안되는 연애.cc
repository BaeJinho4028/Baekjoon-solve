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

int n, m;
char a[1005];
int ans, cnt;

vector<tiii> e;
vector<int> p(1005, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool dif(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;

	p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if (a[u] != a[v]) e.push_back({ d, u, v });
	}
	sort(e.begin(), e.end());

	for (int i = 0; i < e.size(); i++) {
		int a, b, c;
		tie(c, a, b) = e[i];
		if(!dif(a,b)) continue;
		ans += c;
		cnt++;
		if (cnt == n - 1) {
			cout << ans;
			return 0;
		}
	}
	cout << -1;
}