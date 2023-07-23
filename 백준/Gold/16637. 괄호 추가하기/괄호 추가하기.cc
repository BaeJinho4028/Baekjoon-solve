#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int mx = -0x7f7f7f7f;

int cal(int a, int b, char c) {
	if (c == '+') a += b;
	if (c == '-') a -= b;
	if (c == '*') a *= b;

	return a;
}

void dfs(int cur, int num) {
	if (cur >= n) {
		mx = max(mx, num);
		return;
	}

	char op = (cur == 0) ? '+' : s[cur - 1];

	if (cur + 2 < n) {
		int tmp = cal(s[cur] - '0', s[cur + 2] - '0', s[cur + 1]);
		dfs(cur + 4, cal(num, tmp, op));
	}
	dfs(cur + 2, cal(num, s[cur] - '0', op));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	dfs(0, 0);

	cout << mx;
}