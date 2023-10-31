#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		int dif = '????';
		int l = 0, r = n - 1;
		while (l < r) {
			if (dif > abs(k - (v[l] + v[r]))) {
				dif = abs(k - (v[l] + v[r]));
				cnt = 1;
			}
			else if (dif == abs(k - (v[l] + v[r])))
				cnt++;

			if (v[l] + v[r] == k) {
				l++; r--;
			}
			else if (v[l] + v[r] > k) 
				r--;
			else
				l++;
		}

		cout << cnt << '\n';
	}
}