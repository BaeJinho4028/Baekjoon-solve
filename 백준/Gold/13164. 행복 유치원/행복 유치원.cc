#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
long long a[300005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	for (int i = 1; i < n; i++)
		v.push_back(a[i] - a[i - 1]);

	sort(v.begin(), v.end());

	long long ans = 0;
	for (int i = 0; i < n - k; i++) ans += v[i];
	cout << ans;
}