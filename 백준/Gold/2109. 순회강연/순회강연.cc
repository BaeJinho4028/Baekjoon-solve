#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<pair<int, int>> v;
int vis[10005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++) {
		for (int j = v[i].Y; j >= 1; j--) {
			if (!vis[j]) {
				vis[j] = v[i].X;
				break;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 10000; i++) {
		ans += vis[i];
	}

	cout << ans;
}