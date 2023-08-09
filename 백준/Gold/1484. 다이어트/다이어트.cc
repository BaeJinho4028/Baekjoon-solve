#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int g;
	cin >> g;

	int st = 1, en = 2;
	bool flag = false;
	while (st < en) {
		if ((en * en) - (st * st) == g) {
			flag = true;
			cout << en << '\n';
			en++;
		}
		else if ((en * en) - (st * st) < g)
			en++;
		else
			st++;
	}
	if (!flag) cout << -1;
}