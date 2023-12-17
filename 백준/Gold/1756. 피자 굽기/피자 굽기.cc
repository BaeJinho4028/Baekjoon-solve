#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int a[300005], p[300005], idx[300005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d, n;
	cin >> d >> n;

	for (int i = 1; i <= d; i++) {
		cin >> a[i];
		if (i > 1 && a[i] > a[i - 1])
			a[i] = a[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	int cnt = 1;
	for (int i = d; i > 0; i--) {
		if (a[i] >= p[cnt]) {
			idx[cnt] = i;
			cnt++;
		}

		if (cnt > n) break;
	}

	if (cnt > n)
		cout << idx[n];
	else
		cout << 0;
}