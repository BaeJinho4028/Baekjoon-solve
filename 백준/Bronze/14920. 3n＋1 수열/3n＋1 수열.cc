#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

ll n, cnt = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n != 1) {
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		cnt++;
	}

	cout << cnt;
}