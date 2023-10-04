#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char board[1005];
int d[1005];
int n;

int f(int x) {
	if (x == 1) return 0;

	int& ret = d[x];
	if (~ret) return ret;

	ret = '????';

	for (int i = 1; i < n; i++) {
		if (x - i < 1) break;
		if (board[x] == 'J' && board[x - i] != 'O') continue;
		if (board[x] == 'O' && board[x - i] != 'B') continue;
		if (board[x] == 'B' && board[x - i] != 'J') continue;

		ret = min(ret, f(x - i) + i * i);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> board[i];

	memset(d, -1, sizeof(d));
	if (f(n) != '????') cout << f(n);
	else cout << -1;
}