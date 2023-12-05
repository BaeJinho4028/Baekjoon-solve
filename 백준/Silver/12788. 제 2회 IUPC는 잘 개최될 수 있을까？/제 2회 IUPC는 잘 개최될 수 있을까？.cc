#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int c[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;
	a *= b;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n, greater<>());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += c[i];
		if (sum >= a) {
			cout << i + 1;
			return 0;
		}
	}
	cout << "STRESS";

}