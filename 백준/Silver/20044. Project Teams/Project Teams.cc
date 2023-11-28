#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}

	sort(a, a + 2 * n);

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp = a[i] + a[2 * n - i - 1];
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cout << v[0];
}