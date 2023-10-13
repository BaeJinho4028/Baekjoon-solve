#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (1) {
		int cnt = 0;
		string s;
		cin >> s;
		if (s[0] == '-') break;

		stack<char> st;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{') st.push('{');
			else if (s[i] == '}') {
				if (st.empty()) {
					st.push('{');
					cnt++;
				}
				else {
					st.pop();
				}
			}
		}
		
		cnt += st.size() / 2;
		cout << t++ << ". " << cnt << '\n';
	}
}