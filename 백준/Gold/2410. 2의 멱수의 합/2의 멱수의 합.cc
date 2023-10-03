#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[1000005];
int n;
const int MOD = 1000000000;

void f(int x, int a) {
	if (x > n) return;

	d[x] = (d[x] + d[x - a]) % MOD;

	f(x + 1, a);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[0] = 1;
	for (int i = 1; i <= n; i *= 2) {
		f(i, i);
	}

	cout << d[n];

	return 0;
}