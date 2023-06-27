#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= 10; j++) {
			int x;
			cin >> x;

			if (x != (j - 1) % 5 + 1) flag = false;
		}

		if (flag) cout << i << '\n';
	}
}