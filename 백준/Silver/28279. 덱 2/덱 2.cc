#include <bits/stdc++.h>
using namespace std;

int a[5005][5005];
int p[5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	deque<int> dq;
	while (n--) {
		int x;
		cin >> x;

		if (x == 1) {
			int y;
			cin >> y;
			dq.push_front(y);
		}
		else if (x == 2) {
			int y;
			cin >> y;
			dq.push_back(y);
		}
		else if (x == 3) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (x == 4) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (x == 5) {
			cout << dq.size() << '\n';
		}
		else if (x == 6) {
			cout << dq.empty() << '\n';
		}
		else if (x == 7) {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}