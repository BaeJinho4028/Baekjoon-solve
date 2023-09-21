#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int arr[15][15];
bool vis[15]; //선수
bool chk[15]; //포지션
int mx;

void dfs(int cur, int sum, int idx) {
	if (cur == 11) {
		mx = max(mx, sum);
		return;
	}

	for (int i = idx; i < 11; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		for (int j = 0; j < 11; j++) {
			if (chk[j] || arr[i][j] == 0) continue;
			chk[j] = true;
			dfs(cur + 1, sum + arr[i][j], i+1);
			chk[j] = false;
		}
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> arr[i][j];
			}
		}

		mx = 0;
		dfs(0, 0, 0);

		cout << mx << '\n';
	}
}