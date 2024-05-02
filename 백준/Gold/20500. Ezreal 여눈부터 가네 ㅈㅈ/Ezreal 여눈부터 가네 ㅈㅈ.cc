#include <bits/stdc++.h>
using namespace std;

long long d[3][1520]; //나머지, 1의자리를 5로고정했을경우 몇자리수인지  : 의 갯수

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[0][2] = 1; // 15 
	d[1][2] = 1; // 55 
	d[2][2] = 0;

	for (int i = 3; i <= n; i++) {
		d[0][i] = (d[1][i - 1] + d[2][i - 1]) % 1000000007;
		d[1][i] = (d[0][i - 1] + d[2][i - 1]) % 1000000007;
		d[2][i] = (d[0][i - 1] + d[1][i - 1]) % 1000000007;
	}
	
	cout << d[0][n];
}
