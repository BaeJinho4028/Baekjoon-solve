#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	stack<pair<int,int>> st;
	int ans = 0;
	while (n--) {
		int a;
		cin >> a;

		if(a) {
			int b, c;
			cin >> b >> c;
			st.push({ b, c });
		}
		if (!st.empty()) {
			st.top().second--;
			if (st.top().second == 0) {
				ans += st.top().first;
				st.pop();
			}
		}
	}
	cout << ans;
}