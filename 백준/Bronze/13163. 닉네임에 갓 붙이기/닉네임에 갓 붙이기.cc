#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		getline(cin, s);
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (flag && s[i] == ' ') {
				cout << "god";
				flag = false;
			}
			else if (!flag && s[i] != ' ') {
				cout << s[i];
			}
		}
		cout << '\n';
	}
}