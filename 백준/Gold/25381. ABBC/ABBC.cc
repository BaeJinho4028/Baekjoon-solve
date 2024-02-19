#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int ans = 0;

	queue<int> q;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B') q.push(i);
		if (s[i] == 'C' && !q.empty()) {
			s[q.front()] = s[i] = '.';
			q.pop();
			ans++;
		}
	}

	while (!q.empty()) q.pop();

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') q.push(i);
		if (s[i] == 'B' && !q.empty()) {
			q.pop();
			ans++;
		}
	}
	cout << ans;
}