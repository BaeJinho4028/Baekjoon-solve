#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

char board[2005][2005];
int sum[2005][2005];
int n, m, k;

int chk(char c) {
	memset(sum, 0, sizeof(sum));
	int a;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) 
				a = (board[i][j] != c);
			else 
				a = (board[i][j] == c);
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a;
		}
	}

	int mn = '????';
	int cnt;

	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j <= m - k; j++) {
			cnt = sum[i + k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j];
			mn = min(mn, cnt);
		}
	}

	return mn;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cout << min(chk('B'), chk('W'));
}