#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
const int INF = 1000000000;

int a[1005], d[1005];
int n;

int f(int idx) {
	if (idx == n) return 0;

	int& ret = d[idx];
	if (~ret) return ret;

	ret = 0;

	int mn = '????', mx = -1;
	for (int i = idx; i < n; i++) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);

		ret = max(ret, (mx - mn) + f(i + 1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));
	cout << f(0);
}