#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	cout << m - gcd(n, m);
}