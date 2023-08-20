#include <bits/stdc++.h>
using namespace std;

long long d[105];

/*
d[i-1] + 1 (A만 누르는 경우)

d[i-3] * 2 (3칸 전 전체 복붙)
d[i-4] * 3 (4칸 전 전체 복붙 * 2)
d[i-5] * 4 (5칸 전 전체 복붙 * 3)

즉, d[i-j] * (j-1)
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;

	for (int i = 1; i <= 6; i++)
		d[i] = i;

	for (int i = 7; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		for (int j = 3; j < i; j++) {
			d[i] = max(d[i], d[i - j] * (j - 1));
		}
	}

	cout << d[n];
}