#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a2, a1, a0, c;
	double n;
	cin >> a2 >> a1 >> a0 >> c >> n;
	if(a2 != c) n = max((double)a1 / (-2* (a2-c)), (double)n);

	cout << ((a2 * n * n + a1 * n + a0 >= c * n * n) && (a2 >= c));
}