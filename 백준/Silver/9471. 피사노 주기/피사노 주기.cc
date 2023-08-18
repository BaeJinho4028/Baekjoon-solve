#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt;

int solve(int m) {
	v.clear();
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	cnt = 2;

	while (1) {
		v.push_back((v[cnt - 1] + v[cnt]) % m);
		cnt++;

		if (v[cnt - 1] == 1 && v[cnt] == 0) break;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		cout << n << ' ' << solve(m)<< '\n';
	}
}