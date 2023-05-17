#include <bits/stdc++.h>
using namespace std;

int d[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a;
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a;
		}
	}

	int x1, y1, x2, y2, ans;
	while(m--){
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		ans = d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}
}