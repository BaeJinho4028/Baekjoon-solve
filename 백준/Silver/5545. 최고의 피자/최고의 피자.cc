#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int a, b, c; cin >> a >> b >> c; //도우가격, 토핑가격, 도우열량

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), greater<>());

	int mx = c / a;

	for (int i = 0; i < n; i++) {
		a += b;
		c += v[i];
		
		mx = max(mx, c / a);
	}

	cout << mx;
}