#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<pair<int, int>> v;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b}); //끝나는 시간
	}
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	
	pq.push(v[0].Y);
	for (int i = 1; i < n; i++) {
		if (pq.top() <= v[i].X) 
			pq.pop();
		pq.push(v[i].Y);
	}

	cout << pq.size();
}