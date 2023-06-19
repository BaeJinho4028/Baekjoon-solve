#include <bits/stdc++.h>
using namespace std;

int board[25][25];
bool vis[25];
int mn = 0x7f7f7f7f;
int n;

int chk() {
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (vis[i] && vis[j])
				a += board[i][j] + board[j][i];
			if (!vis[i] && !vis[j])
				b += board[i][j] + board[j][i];
		}
	}

	return abs(a - b);
}

void solve(int cur) {
	if (cur == n) {
		mn = min(mn, chk());
		return;
	}

	solve(cur + 1); //포함

	vis[cur] = true; //포함x
	solve(cur + 1);
	vis[cur] = false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	solve(0);

	cout << mn;
}