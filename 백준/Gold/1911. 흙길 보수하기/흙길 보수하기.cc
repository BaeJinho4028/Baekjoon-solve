#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;

	vector<pii> v;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	int cnt = 0, st = 0;

	for (int i = 0; i < n; i++) {
		if (st < v[i].X)
			st = v[i].X;

		while (st < v[i].Y) {
			st += l;
			cnt++;
		}
	}

	cout << cnt;
}