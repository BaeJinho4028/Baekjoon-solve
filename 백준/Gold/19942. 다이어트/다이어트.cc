#include <bits/stdc++.h>
using namespace std;

int t[20][5];
int mn = '????';
int n;
int a, b, c, d;
vector<string> ans;

void bt(int cur, int w, int x, int y, int z, int sum, string s) {
	if (w >= a && x >= b && y >= c && z >= d) {
		if (sum == mn) {
			ans.push_back(s);
		}
		else if (sum < mn) {
			ans.clear();
			ans.push_back(s);
			mn = sum;
		}
		
		return;
	}

	for (int i = cur; i < n; i++) {
		bt(i + 1, w + t[i][0], x + t[i][1], y + t[i][2], z + t[i][3], sum + t[i][4], s + ' ' + to_string(i + 1));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	cin >> a >> b >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> t[i][j];
		}
	}

	bt(0, 0, 0, 0, 0, 0, "");
	sort(ans.begin(), ans.end());

	if (mn == '????') {
		cout << -1;
		return 0;
	}

	cout << mn << '\n';
	for (int i = 1; i < ans[0].size(); i++)
		cout << ans[0][i];
}