#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<string> v;
	vector<int> w;
	for (int i = 0; i < n; i++) {
		string s;
		int a;
		cin >> s >> a;
		v.push_back(s);
		w.push_back(a);
	}

	while (m--) {
		int a;
		cin >> a;

		int idx = lower_bound(w.begin(), w.end(), a) - w.begin();
		cout << v[idx] << '\n';
	}
}