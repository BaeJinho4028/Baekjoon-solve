#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> v;

bool chk(int mid) {
	int cnt = 0;
	for (int i = 1; i < v.size(); i++) {
		int d = v[i] - v[i - 1];
		cnt += d / mid;
		if (d % mid == 0) cnt--; //이미 있는위치
	}

	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l;
	
	v.push_back(0);
	v.push_back(l);
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int st = 1, en = l;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (chk(mid)) en = mid - 1;
		else st = mid + 1;
	}

	cout << st;
}