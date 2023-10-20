#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[30005], b[30005];
int mx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) b[i]++;
			else break;
		}
		mx = max(mx, b[i]);
	}

	cout << mx;
}