#include <bits/stdc++.h>
using namespace std;

int a, k;
int d[1000005];

int f(int x) {
	if (x > k) return '????';
	if (x == k) return 0;

	int& ret = d[x];
	if (~ret) return ret;
	
	ret = min(f(x + 1), f(x * 2)) + 1;

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> k;

	memset(d, -1, sizeof(d));
	cout << f(a);
}