#include <bits/stdc++.h>
using namespace std;

bool qs[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> qs[i];

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(qs[i]==0) dq.push_back(x);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		dq.push_front(x);
		cout << dq.back() << ' ';
		dq.pop_back();
	}
}