#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int cnt = 1;

	vector<int> v;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.push(x);
		while (!st.empty() && st.top() == cnt) {
			cnt++;
			st.pop();
		}
	}

	if (cnt == n + 1) cout << "Nice";
	else cout << "Sad";
}