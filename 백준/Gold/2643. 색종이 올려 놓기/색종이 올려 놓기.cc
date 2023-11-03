#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int d[105];
vector<pair<int,int>> v;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ min(a, b), max(a, b) });
	}

	sort(v.begin(), v.end());

	int ans = 1;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].X >= v[j].X && v[i].Y >= v[j].Y) {
				d[i] = max(d[i], d[j] + 1);
			}
		}

		ans = max(ans, d[i]);
	}

	cout << ans;
}