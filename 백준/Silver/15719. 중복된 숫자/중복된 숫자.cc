#include <bits/stdc++.h>
using namespace std;

bool chk[10000005];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (chk[x] == true) {
			cout << x;
			break;
		}
		chk[x] = true;
	}
}
