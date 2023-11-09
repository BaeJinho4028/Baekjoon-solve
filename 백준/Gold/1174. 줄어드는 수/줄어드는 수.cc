#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n;
vector<ll> v;

void bt(int cur, ll num) {
	if (cur > 10) return;
	v.push_back(num);
	for (int i = num % 10 - 1; i >= 0; i--) {
		bt(cur + 1, num * 10 + i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i <= 9; i++) {
		bt(1, i);
	}

	sort(v.begin(), v.end());

	(n > v.size()) ? cout << "-1" : cout << v[n - 1];
}