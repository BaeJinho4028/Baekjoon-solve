#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	sort(a, a + m);

	int mxE = 0, mx = 0;
	for (int i = 0; i < m; i++) {
		int tmp = a[i] * min(n, m - i);
		if (tmp > mx) {
			mx = tmp;
			mxE = i;
		}
	}

	cout << a[mxE] << ' ' << mx;
}