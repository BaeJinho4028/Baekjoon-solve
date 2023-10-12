#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1000000009;
ll d[100005];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1] = 1; // 1
	d[2] = 2; // 1 1     2
	d[3] = 2; // 1 1 1    3
	d[4] = 3; // 1 1 1 1  2 2   1 2 1 
	d[5] = 3;  // 1 1 1 1 1   2 1 2   1 3 1 
	d[6] = 6;  // 111111 1221 2112 222 33 11211

	for (int i = 7; i <= 100000; i++) {
		d[i] = (d[i - 2] + d[i - 4] + d[i - 6]) % INF;
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		cout << d[n] << '\n';
	}
}