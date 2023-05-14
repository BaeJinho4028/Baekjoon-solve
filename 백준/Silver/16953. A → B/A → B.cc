#include <bits/stdc++.h>
using namespace std;

long long a, b;
int ans = 10000;

void dfs(long long cur, int cnt) {
	if (cur > b) return;

	if (cur == b) 
		ans = min(ans, cnt);
	
	dfs(cur * 2, cnt + 1);
	dfs(cur * 10 + 1, cnt + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> a >> b;

	dfs(a, 1);

	if (ans == 10000) cout << -1;
	else  cout << ans;
}