#include <bits/stdc++.h>
using namespace std;

char a[500005];
int r, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i - 1] != 'R' && a[i] == 'R') r++;
		if (a[i - 1] != 'B' && a[i] == 'B') b++;
	}
	cout << min(r, b) + 1;
}