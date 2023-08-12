#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		stack<char> st;
		int e = 1;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(') {
				st.push(s[i]);
			}
			else if (!st.empty() && s[j] == ')') {
				st.pop();
			}
			else {
				e = 0;
				break;
			}
		}
		if (st.empty() && e == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}