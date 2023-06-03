#include <bits/stdc++.h>
using namespace std;

bool vis[10];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	while (cin >> a >> b) {
		int ans = 0;
		for (int i = a; i <= b; i++) {
			string s = to_string(i);

			memset(vis, false, sizeof(vis));

			bool flag = false;
			for (int j = 0; j < s.size(); j++) {
				if (vis[s[j] - '0']) {
					flag = true;
					break;
				}
				vis[s[j] - '0'] = true;
			}
			
			if (!flag) ans++;
		}
		cout << ans << '\n';
	}
}
