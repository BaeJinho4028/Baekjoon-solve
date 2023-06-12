#include <bits/stdc++.h>
using namespace std;

int x[4] = { 1,5,10,50 };
int n, ans;
bool vis[1005];

void solve(int num, int cur, int idx) { //idx안하면 시간초과 : 어차피 IXI든 XII든 똑같으니
	if (cur == n) {
		if (vis[num]) return;
		vis[num] = true;
		ans++;
		return;
	}

	for (int i = idx; i < 4; i++) {
		solve(num + x[i], cur + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	solve(0, 0, 0);

	cout << ans;
}