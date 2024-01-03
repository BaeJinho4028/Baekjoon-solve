#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	stack<char> st;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') st.push(s[i]);
		if (s[i] == 'A') {
			if (st.size() >= 2 && s[i+1] == 'P') {
				st.pop();
				i++;
			}
			else {
				cout << "NP";
				return 0;
			}
		}
	}

	if (st.size() > 1) cout << "NP";
	else cout << "PPAP";
}