#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<double> pq;

	for (int i = 0; i < n; i++) {
		double tmp;
		cin >> tmp;

		if (pq.size() == 7) {
			pq.push(tmp); pq.pop();
		}
		else
			pq.push(tmp);
	}

	vector<double> v;
	while (!pq.empty()) {
		v.push_back(pq.top()); pq.pop();
	}

	cout << fixed;
	cout.precision(3);
	for (int i = 6; i >= 0; i--)
		cout << v[i] << '\n';
}