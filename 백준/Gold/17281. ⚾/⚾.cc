#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int player[55][15];
int order[15];
int n, ans;

void solve() {
	int score = 0;
	int st = 1;

	for (int i = 1; i <= n; i++) {
		int out = 0;
		bool nxt = false;
		int base[4] = { 0, };

		while (1) {
			for (int j = st; j <= 9; j++) {
				int p = player[i][order[j]];

				if (p == 0) out++;

				else if (p == 1) {
					for (int k = 3; k >= 1; k--) {
						if (base[k] == 1) {
							if (k == 3) {
								base[k] = 0;
								score++;
							}
							else {
								base[k + 1] = 1;
								base[k] = 0;
							}
						}
					}
					base[1] = 1;
				}

				else if (p == 2) {
					for (int k = 3; k >= 1; k--) {
						if (base[k] == 1) {
							if (k == 3 || k == 2) {
								base[k] = 0;
								score++;
							}
							else {
								base[k + 2] = 1;
								base[k] = 0;
							}
						}
					}
					base[2] = 1;
				}

				else if (p == 3) {
					for (int k = 3; k >= 1; k--) {
						if (base[k] == 1) {
							base[k] = 0;
							score++;
						}
					}
					base[3] = 1;
				}

				else if (p == 4) {
					for (int k = 3; k >= 1; k--) {
						if (base[k] == 1) {
							base[k] = 0;
							score++;
						}
					}
					score++;
				}


				if (out == 3) {
					st = j%9 + 1;
					nxt = true;
					break;
				}
			}
			if (nxt == true) break;
			st = 1;
		}
	}

	ans = max(ans, score);
}

void dfs(int cur) {
	if (cur > 9) {
		solve();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (order[i] != 0) continue;
		order[i] = cur;
		dfs(cur + 1);
		order[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> player[i][j];
		}
	}


	order[4] = 1;
	dfs(2);

	cout << ans;
}