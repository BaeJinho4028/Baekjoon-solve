#include <bits/stdc++.h>
using namespace std;

int a[105], b[105]; //추천수, 기간

bool cmp(int& x, int& y) {
	if (a[x] == a[y]) {
		return b[x] < b[y];
	}
	return a[x] > a[y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v;
	for(int i=0; i<m; i++) {
		int x;
		cin >> x;

		a[x]++;

		for (int j = 0; j < v.size(); j++)
			b[v[j]]++;

		bool flag = false;

		for (int j = 0; j < v.size(); j++) { //이미 있는 후보인지 확인
			if (v[j] == x) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			if (v.size() < n)
				v.push_back(x);
			else {
				sort(v.begin(), v.end(), cmp);
				a[v[n-1]] = 0;
				b[v[n-1]] = 0;
				v[n-1] = x;
			}
		}
	}

	sort(v.begin(), v.end());

	for (auto c : v)
		cout << c << ' ';
}