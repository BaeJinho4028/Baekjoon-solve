#include <bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005][1005];

int f(int l, int r, int turn) {
	int& ret = d[l][r];
	if (~ret) return ret;

	if (l > r) return ret = 0;

	if (turn % 2 == 0) //근우 차례
		return ret = max(a[l] + f(l + 1, r, turn + 1), a[r] + f(l, r - 1, turn + 1));
	else //명우 차례
		return ret = min(f(l + 1, r, turn + 1), f(l, r - 1, turn + 1));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		memset(d, -1, sizeof(d));
		cout << f(1, n, 0) << '\n';
	}

}