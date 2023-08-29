#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };
int n, m;
ll mx, mn = '????';

bool vis[55];
string s;

int dfs(int cur) {
	int cnt = 0;

	for (int i = cur; i < s.size(); i++) {
		char c = s[i];
		if (c == '(' && !vis[i]) {
			vis[i] = true;
			cnt--;
			cnt += (int)(s[i - 1] - '0') * dfs(i + 1);
		}
		else if (c == ')' && !vis[i]) {
			vis[i] = true;
			return cnt;
		}
		else if(!vis[i]) {
			vis[i] = true;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cout << dfs(0);
}