#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> st;
	int mx = 0;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		mx = max(mx, x);

		if (st.empty()) st.push(x);
		else {
			if (st.top() == x) continue;
			else if (st.top() < x) 
				ans += x - st.top();
			st.pop();
			st.push(x);
		}
	}

	while (!st.empty()) {
		int tmp = st.top();
		st.pop();
		ans += mx - tmp;
	}

	cout << ans;
}