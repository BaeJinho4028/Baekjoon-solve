#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int cnt = 1;
	int ans = 0;
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= i; j++) {
			if (cnt >= a && cnt <= b)
				ans += i;
			cnt++;
		}
	}

	cout << ans;
}
