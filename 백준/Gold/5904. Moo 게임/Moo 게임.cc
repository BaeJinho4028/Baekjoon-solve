#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int n;
string s = "moo";

void solve(int k, int len) {
	if (n <= 3) {
		cout << s[n - 1];
		return;
	}

	int nxt = len * 2 + k + 3;
	if (n > nxt) {
		solve(k + 1, nxt);
	}
	else {
		if (n == len + 1) {
			cout << 'm';
			return;
		}
		else if (n <= len + k + 3) {
			cout << 'o';
			return;
		}
		else {
			n -= (len + k + 3);
			solve(1, 3);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	solve(1, 3);
}