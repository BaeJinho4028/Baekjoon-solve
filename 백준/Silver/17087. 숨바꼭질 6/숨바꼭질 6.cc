#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s;
	cin >> n >> s;

	int a;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(abs(s - a));
	}
	
	if (n == 1) {
		cout << v[0];
		return 0;
	}

	int tmp = gcd(v[0], v[1]);

	for (int i = 2; i < n; i++) {
		tmp = gcd(tmp, v[i]);
	}

	cout << tmp;
}