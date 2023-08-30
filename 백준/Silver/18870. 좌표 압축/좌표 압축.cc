#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n;
	cin >> n;

	vector<int> v, u;
	int x[1000005];


	for (int i = 0; i < n; i++) {
		cin >> x[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i] != v[i - 1])
			u.push_back(v[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << lower_bound(u.begin(), u.end(), x[i]) - u.begin() << ' ';
	}
}