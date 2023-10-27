#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n;
int d[15][105][1 << 10];
int ans = 0;
const int INF = 1000000000;

int f(int num, int digit, int bit) {
	if (digit == n) {
		if (bit == (1 << 10) - 1) return 1;
		return 0;
	}

	int& ret = d[num][digit][bit];
	if (~ret) return ret;
	ret = 0;


	if (num < 9) {
		int nxt = num + 1;
		ret += f(nxt, digit + 1, (bit | 1 << (nxt)));
	}
	if (num > 0) {
		int nxt = num - 1;
		ret += f(nxt, digit + 1, (bit | 1 << (nxt)));
	}

	ret %= INF;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	memset(d, -1, sizeof(d));
	for (int i = 1; i <= 9; i++) {
		ans += f(i, 1, 1 << i);
		ans %= INF;
	}
	cout << ans;
}