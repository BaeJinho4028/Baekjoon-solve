#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;
	while (cin >> n) {
		if (n == -1) break;
		sum += n;
	}
	cout << sum;
}