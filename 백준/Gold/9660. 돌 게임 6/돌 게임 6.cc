#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	n %= 7;

	if (n == 0 || n == 2) cout << "CY";
	else cout << "SK";
}