#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int n;
	cin >> n;

	deque<pair<int, int>> dq;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		dq.push_back({ x, i });
	}

	while (!dq.empty()) {
		int tmp = dq.front().first;
		cout << dq.front().second << ' ';
		dq.pop_front();
		if (dq.empty())break;
		if (tmp > 0) {
			for (int i = 0; i < tmp - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < -tmp ; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
}