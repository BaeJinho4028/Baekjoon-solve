#include <bits/stdc++.h>
using namespace std;

int az[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	vector<int> v;
	for (int i = 0; i < a.size(); i++) {
		v.push_back(az[a[i] - 'A']);
		v.push_back(az[b[i] - 'A']);
	}

	while (1) {
		vector<int> tmp;
		for (int i = 0; i < v.size() - 1; i++) {
			tmp.push_back((v[i] + v[i + 1]) % 10);
		}

		v = tmp;

		if (v.size() == 2) {
			cout << v[0] << v[1] << '\n';
			return 0;
		}
	}
}