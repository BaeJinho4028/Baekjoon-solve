#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int chk(char c) {
	if (c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else
		return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<char> op;

	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			cout << s[i];
			continue;
		}


		if (s[i] == '(') {
			op.push(s[i]);
		}
		else if (s[i] == ')') {
			while (op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
		else {
			while (!op.empty() && chk(op.top()) >= chk(s[i])) {
				cout << op.top();
				op.pop();
			}
			op.push(s[i]);
		}
	}

	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
}
