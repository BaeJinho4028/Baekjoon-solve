#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
bool vis[10];
int n;
int mn = 0x7f7f7f7f;

void solve(int m, int a, int b, int cur, int idx) { //개수, 신맛 , 쓴맛 , 깊이 , 순서(조합)
	if (cur == m) {
		mn = min(mn, abs(a - b));
		return;
	}

	for (int i = idx; i < n; i++) {
		if (vis[i]) continue;

		vis[i] = true;
		solve(m, a * v[i].first, b + v[i].second, cur + 1, i+1);
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	for (int i = 1; i <= n; i++)
		solve(i, 1, 0, 0, 0);

	cout << mn;
}