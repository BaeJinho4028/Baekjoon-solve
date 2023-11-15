#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<pair<ll, ll>> v;
ll sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ a, b });
		sum += b;
	}

	sort(v.begin(), v.end());
	
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cur += v[i].second;
		if (cur >= (sum + 1) / 2) {
			cout << v[i].first;
			break;
		}
	}
}
