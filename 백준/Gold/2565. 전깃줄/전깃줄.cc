#include <bits/stdc++.h>
using namespace std;

int d[105];

int main() { //왼쪽을 정렬한후   전체 전선 - 오른쪽가장긴증가하는부분수열 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		d[i] = 1;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) d[i] = max(d[i], d[j] + 1);
		}
	}

	cout << n - *max_element(d, d + n);
}