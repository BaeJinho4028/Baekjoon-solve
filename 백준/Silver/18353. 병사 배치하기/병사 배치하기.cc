#include <bits/stdc++.h>
using namespace std;

int a[2005], d[2005];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j]) d[i] = max(d[i], d[j] + 1);
		}
		mx = max(mx, d[i]);
	}

	cout << n - mx;
}