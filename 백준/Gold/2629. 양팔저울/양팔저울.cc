#include <bits/stdc++.h>
using namespace std;

int n, t;
int w[35];
bool d[15005][35];

void dfs(int cur, int num) {
	if (cur > n || d[num][cur]) return;

	d[num][cur] = true;

	dfs(cur + 1, abs(num - w[cur])); //왼쪽
	dfs(cur + 1, num + w[cur]); //오른쪽
	dfs(cur + 1, num);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];

	dfs(0, 0);

	cin >> t;
	while (t--) {
		int x;
		cin >> x;

		if (x > 15000) cout << "N ";
		else if (d[x][n]) cout << "Y ";
		else cout << "N ";
	}
}