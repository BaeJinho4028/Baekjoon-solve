#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };
int n, m;
int mx, mn = '????';
int ans, cnt;

int a[10];
bool vis[10];

void dfs(int cur, int num) {
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		if (num + a[i] - m < 500) continue;

		vis[i] = true;
		dfs(cur + 1, num + a[i] - m);
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dfs(0, 500);

	cout << cnt;
}