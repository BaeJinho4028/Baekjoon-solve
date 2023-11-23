#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b, a });
	}

	sort(v.begin(), v.end(), greater<>());

	int ans = v[0].X;
	for (int i = 0; i < n; i++) {
		ans = min(ans, v[i].X) - v[i].Y;
	}

	cout << ans;
}