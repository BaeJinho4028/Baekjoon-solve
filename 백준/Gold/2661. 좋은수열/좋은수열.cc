#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n;

void dfs(int cur, string s) {
	for (int i = 1; i <= s.size() / 2; i++) {
		if (s.substr(s.size() - i, i) == s.substr(s.size() - (i * 2), i)) 
			return;
	}

	if (cur == n) {
		cout << s;
		exit(0);
	}

	dfs(cur + 1, s + '1');
	dfs(cur + 1, s + '2');
	dfs(cur + 1, s + '3');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dfs(0, "");
}