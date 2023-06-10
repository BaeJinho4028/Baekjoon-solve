#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	cout << a[(n-1) / 2];
}