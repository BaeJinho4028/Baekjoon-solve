#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	int t;
	cin >> n;
	stack<pair<int, int>> st;

	for (int i = 0; i < n; i++) {
		cin >> t;
		while(!st.empty()) {
			if (st.top().first > t) {
				cout << st.top().second << ' ';
				break;
			}
			st.pop();
		}		
		if (st.empty()) {
			cout << 0 << ' ';
		}
		st.push({ t , i + 1});
	}
}