#include <bits/stdc++.h>
using namespace std;

int n, t;
int k, s;
int d[100005];

/*
중복이 안되므로 뒤부터 돈다.
중복이 된다면 앞부터 돈다.
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> k >> s;
		for (int j = t; j >= k; j--) {
			d[j] = max(d[j], d[j - k] + s);
		}
	}

	cout << d[t];
}