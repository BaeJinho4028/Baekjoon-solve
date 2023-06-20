#include <bits/stdc++.h>
using namespace std;

int d[35];

//특별한 모양 2가지
//F[N] = (F[N-2]*F[2]) + (F[N-4]*2) + (F[N-6]*2) + (F[N-8]*2) + ... + ( F[0] * 2 )
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[0] = 1;
	d[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		d[i] += d[i - 2] * d[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
	}

	cout << d[n];
}