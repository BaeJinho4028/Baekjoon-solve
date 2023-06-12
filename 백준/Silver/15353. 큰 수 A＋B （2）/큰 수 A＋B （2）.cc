#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	if (a.size() < b.size()) swap(a, b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector<int> v;

	for (int i = 0; i < b.size(); i++)
		v.push_back((a[i] - '0') + (b[i] - '0'));
	for (int i = b.size(); i < a.size(); i++)
		v.push_back(a[i] - '0');


	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= 10) {
			if (i == v.size() - 1)
				v.push_back(0);
			v[i + 1]++;
			v[i] %= 10;
		}
	}

	reverse(v.begin(), v.end());

	for (auto x : v)
		cout << x;
}